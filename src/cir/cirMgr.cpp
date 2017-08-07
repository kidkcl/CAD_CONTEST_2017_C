// File name [ cirMgr.cpp ]
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <bitset>
#include <unordered_set>

#include "cir/cirMgr.h"
#include "util/parse.h";

using namespace std;

void
CirMgr::test()
{

	removeInvBuf();

    _dupF = dupNet(_F);
    _dupG = dupNet(_G);
	
	if( _debug ) {
		std::cout << "report F: " << std::endl;
		_F -> reportNetList();
		std::cout << "report G: " << std::endl;
		_G -> reportNetList();
		std::cout << "report _dupF: " << std::endl;
		_dupF -> reportNetList();
		std::cout << "report _dupG: " << std::endl;
		_dupG -> reportNetList();
	}


	sortCandidate();	// sort by increasing weight
/*
	if( _debug ) {
		std::cout << "report sortedCand: " << std::endl;
		reportSortedCand();
		//for( unsigned i = 0; i < _candNameList.size(); ++i )
		//	std::cout << _candNameList[i] << std::endl;
	}
*/
	createVar4CostSolver();


/*************************************/
// simulation based cut generalization
/*************************************/

	initCandSolver();
	setUpCandSolver();
	assignmentVec t_1, t_0;
	idxVec candIdx;
	idxVec cutIdx;
   idxVec generalizedCut;
/*
	randSim(_F);
	knownSim(_G, _F);
	if( _debug ) {
		std::cout << "F simV: " << std::endl;
		_F -> reportSimV();
		std::cout << "G simV: " << std::endl;
		_G -> reportSimV();
	}
	unsigned startIdx = 0;
	addCandIdx(candIdx, startIdx, 10);
	analyzeVec(t_1, t_0, candIdx);
	std::cout << "potential cut size: " << candIdx.size() << std::endl;
	if( _debug ) {
		std::cout << "t1 size: " << t_1.size() << std::endl;
		for( unsigned i = 0 ; i < t_1.size(); ++i ) 
			std::cout << std::bitset<32>(t_1[i]) << std::endl;
		std::cout << "t0 size: " << t_0.size() << std::endl;
		for( unsigned i = 0 ; i < t_0.size(); ++i ) 
			std::cout << std::bitset<32>(t_0[i]) << std::endl;
	}
	if( checkValidCut(t_1, t_0) ) {
		std::cout << "valid cut" << std::endl;
		generalizeCut(t_1, t_0, candIdx, cutIdx);
		std::cout << "generalized Cut: " << std::endl;
		for( unsigned i = 0; i < cutIdx.size(); ++i )
			std::cout << _sortedCandGate[i] -> getName() << std::endl;
	}
	else std::cout << "invalid cut" << std::endl;
*/
/*************************************/

	getCut(cutIdx);
	for( unsigned i = 0; i < cutIdx.size(); ++i )
		std::cout << _sortedCandGate[cutIdx[i]] -> getName() << std::endl;


	cutIdx.clear();
   for( unsigned i = 0; i < _sortedCandGate.size(); ++i ) cutIdx.push_back(i);

	vector<Lit> Lit_vec_origin;
	//assumeCut(Lit_vec_origin);
   //assumeCut(candIdx, Lit_vec_origin);
   assumeCut(cutIdx, Lit_vec_origin);
	if( _debug ) {
		std::cout << "report Lit_vec_origin: " << std::endl;
		for( unsigned i = 0; i < Lit_vec_origin.size(); ++i ) {
			std::cout << var(Lit_vec_origin[i]) << "(" << sign(Lit_vec_origin[i]) << ")" << std::endl;
		}
	}
   std::cout << "# clauses in cand solver: " << _candSolver -> getNumClauses() << std::endl;
	_candSolver -> simplify();
	bool candSAT = _candSolver -> assump_solve();
	if( candSAT ) std::cout << "candSAT" << std::endl;
	else {
      std::cout << "candUNSAT" << std::endl;
		std::cout << "before UNSATGen, size: " << cutIdx.size() << std::endl;
		std::cout << "cost: " << getCost(cutIdx) << std::endl;
      UNSATGeneralizationWithUNSATCore(cutIdx, Lit_vec_origin, generalizedCut);
		std::cout << "after UNSATGen, size: " << generalizedCut.size() << std::endl;
		std::cout << "cost: " << getCost(generalizedCut) << std::endl;
/*
		for( unsigned i = 0; i < generalizedCut.size(); ++i ) {
			std::cout << _sortedCandGate[generalizedCut[i]] -> getName() << std::endl;
		}
*/
   }

	//if( !candSAT ) generatePatch();
	if( !candSAT ) generatePatch(generalizedCut);

	//generatePatch();
	//generatePatch(generalizedCut);




/*
	std::vector<bool> assign(_candNameList.size(), false);
	_blockingClauses.push_back(assign);
	assert(_blockingClauses.size() == 1);
*/

//	modified to test
/*
	assign[4] = true;
	_blockingClauses.push_back(assign);
	assign[4] = false; assign[6] = true;
	_blockingClauses.push_back(assign);
	assign[5] = true;
	_blockingClauses.push_back(assign);
	assign[5] = false; assign[3] = true;
	_blockingClauses.push_back(assign);
	assign[3] = false; assign[6] = false;
	assign[4] = true; assign[5] = true;
	_blockingClauses.push_back(assign);
*/	
// end of modification

	//unsigned totalCost = getTotalCost();
	//if(getMuxAssignment()) reportMuxAssignment();

/*
	unsigned count = 0;
	while( 1 ) {
		++count;
		_costSolver -> reset();
		if( count == 1) createVar4CostSolver(true);
		else createVar4CostSolver(false);
		// get an assignment, then call tieGate

		addCostConstraint(std::floor(totalCost/_sortedCandGate.size()) * count);
		//addCostConstraint(std::floor(totalCost/3) * count);
		addAllBlockings();
		while( getMuxAssignment() ) {
			std::cout << "current assignment: ";
			reportMuxAssignment();
			std::cout << std::endl;
			addBlockingAssignment(_muxAssignment);
			_blockingClauses.push_back(_muxAssignment);
			_s -> reset();
			createVar(_F);
			createVar(_G);
			createVar(_dupF);
			createVar(_dupG);
			// tie gate with '1' assignment
			tieGateWithAssignment(_muxAssignment);
			addToSolver(_F);
			addToSolver(_G);
			addXorConstraint(_F, _G);
			addErrorConstraint(_F, 1);
		
			addToSolver(_dupF);
			addToSolver(_dupG);
			addXorConstraint(_dupF, _dupG);
			addErrorConstraint(_dupF, 0);

			_s -> simplify();
			_s -> assumeRelease();
			for( unsigned i = 0; i < _sortedCandGate.size(); ++i ) {
				CirGate* sel = _F -> getPi(_G -> getPiNum() + i);
				//std::cout << "sel name: " << sel -> getName() << std::endl;
				if( _muxAssignment[i] ) _s -> assumeProperty(sel -> getVar(), false);
				else _s -> assumeProperty(sel -> getVar(), true);
			}
			bool isSat = _s -> assump_solve();
			cout << (isSat ? "SAT" : "UNSAT") << endl;
			
			if( !isSat ) return;
			else {
				// restore the tied Gate
				restoreTiedGates();
			}
		}
	}
*/
}

void
CirMgr::createMux4Candidates()
{
	assert(_F && _G && _dupF && _dupG && _candNameList.size());
	for( unsigned i = 0; i < _candNameList.size(); ++i ) {
		const string& name = _candNameList[i];
		//cout << "muxing: " << name << endl;
		CirGate* g_F = _F -> getGateByName(name);
		CirGate* g_dupF = _dupF -> getGateByName(name);
		assert(g_F -> getName() == g_dupF -> getName());
		// the created mux gate should be inserted to _F
		CirGate* mux = _F -> createMux(g_F, g_dupF);
	}
}

//CirNet* out = 0;
/*
CirNet*
CirMgr::miterCkt(CirNet* f, CirNet* g)
{
        ofstream out("miter.v", ios::out);
        out << "module top(";

}*/

void
CirMgr::removeInvBuf()
{
	//std::cout << "before removement, size: " << _candNameList.size() << std::endl;
	_F -> removeInvBuf(_candNameList);
	//std::cout << "after removement, size: " << _candNameList.size() << std::endl;

	
	
	// _G could be stored as aig, and utilize fraig to simplify netlist
	std::vector<std::string> tmp;
	//std::cout << "before G_remove " << std::endl;
	//_G -> reportNetList();
	_G -> removeInvBuf(tmp);
	//std::cout << "after G_remove " << std::endl;
	//_G -> reportNetList();
}

void
CirMgr::writeToPatch(const string& fileName)
{
    std::ofstream ofs(fileName.c_str());
    size_t max = _patch -> getPiNum() - 1;
    // write header
    ofs << "module patch (";
    for( unsigned i = 0; i < _patch -> getPoNum(); ++i ) {
        ofs << _patch -> getPo(i) -> getName() << ", ";
    }
    for( unsigned i = 0; i < _patch -> getPiNum(); ++i ) { // FIXME: PI is the valid cut we chose
        ofs << _patch -> getPi(i) -> getName() << (i == max ? ");" : ", ");
    }
    ofs << endl;
    // write input
    ofs << "input ";
    for( unsigned i = 0; i < _patch -> getPiNum(); ++i ) { // FIXME
        ofs << _patch -> getPi(i) -> getName() << (i == max ? ";" : ", ");
    }
    ofs << endl;
    // write output
    ofs << "output " << _patch -> getPo(0) -> getName() << ";" << endl;
    // write wire
    max = _patch -> getGateNum() - 1;
    ofs << "wire ";
    for( unsigned i = 0; i < _patch -> getGateNum(); ++i ) {
        ofs << _patch -> getGate(i) -> getName() << (i == max ? ";" : ", ");
    }
    ofs << endl;
    // write gate
    //GateList topoList = _patch -> buildTopoList();
    for( unsigned i = 0; i < _patch -> getGateNum(); ++i ) {
       CirGate* g = _patch -> getGate(i);
       switch( g -> getType() ) {
           case Gate_And:
               ofs << "and (" << g -> getName() << ", ";
               ofs << (g->isFaninInv(0) ? "!":"") << g -> getFanin(0) -> getName() << ", " << (g->isFaninInv(1) ? "!":"") << g -> getFanin(1) -> getName() << ");" << endl;
               break;
           case Gate_Buf:
               ofs << "buf(" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ");" << endl;
               break;
           case Gate_Inv:
               ofs << "not(" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ");" << endl;
               break;
           case Gate_Or:
               ofs << "or (" << g -> getName() << ", ";
               ofs << (g->isFaninInv(0) ? "!":"") <<  g -> getFanin(0) -> getName() << ", " << (g->isFaninInv(1) ? "!":"") <<  g -> getFanin(1) -> getName() << ");" << endl;
               break;
           case Gate_Nand:
               ofs << "nand (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
               break;
           case Gate_Nor:
               ofs << "nor (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
               break;
           case Gate_Xnor:
               ofs << "xnor (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
               break;
           case Gate_Xor:
               ofs << "xor (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
               break;
           default:
               break;
       }
    }
    ofs << "endmodule";
    ofs.close();
}

void
CirMgr::writeToOut(const string& fileName, const string& inpuFile)
{
    std::ofstream ofs(fileName.c_str());
    std::ifstream ifs(inpuFile.c_str()); // read the original F.v
    std::string str;
    std::vector<string> tokens;
    size_t max = _F -> getPiNum() - 1;
    if(ifs.fail()) cerr << "fail to read F.v!!" << endl;
    while(!ifs.eof()) {
        str = readUntil(ifs, ';');
        tokens = split(str, ";\t\n");
        if(!tokens[0].compare("endmodule")) break;
        ofs << str;
    }
    ofs << endl;
    ifs.close();
    /*
    // write header
    ofs << "module top (";
    for( unsigned i = 0; i < _F -> getPoNum(); ++i ) {
        ofs << _F -> getPo(i) -> getName() << ", ";
    }
    for( unsigned i = 0; i < _F -> getPiNum(); ++i ) {
        ofs << _F -> getPi(i) -> getName() << (i == max ? ");" : ", ");
    }
    ofs << endl;
    // write input
    ofs << "input ";
    for( unsigned i = 0; i < _F -> getPiNum(); ++i ) {
        ofs << _F -> getPi(i) -> getName() << (i == max ? ";" : ", ");
    }
    ofs << endl;
    // write output
    ofs << "output ";
    max = _F -> getPoNum() - 1;
    for( unsigned i = 0; i < _F -> getPoNum(); ++i ) {
        ofs << _F -> getPo(i) -> getName() << (i == max ? ";" : ", ");
    }
    ofs << endl;
    // write wire
    ofs << "wire ";
    max = _F -> getGateNum() - 1;
    for( unsigned i = 0; i < _F -> getGateNum(); ++i ) {
        ofs << _F -> getGate(i) -> getName() << (i == max ? ";" : ", ");
    }
    ofs << endl;
    // write error
    ofs << "wire ";
    max = _F -> getErrorNum() - 1;
    for( unsigned i = 0; i < _F -> getErrorNum(); ++i ) {
        ofs << _F -> getError(i) -> getName() << (i == max ? ";" : ", ");
    }
    ofs << endl;
    // write gate list
    GateList totList = _F -> totGateList();
    for( unsigned i = 0; i < totList.size(); ++i ) {
        CirGate* g = totList[i];
        switch( g -> getType() ) {
            case Gate_And:
                ofs << "and (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
                break;
            case Gate_Buf:
                ofs << "buf(" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ");" << endl;
                break;
            case Gate_Inv:
                ofs << "not(" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ");" << endl;
                break;
            case Gate_Or:
                ofs << "or (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
                break;
            case Gate_Nand:
                ofs << "nand (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
                break;
            case Gate_Nor:
                ofs << "nor (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
                break;
            case Gate_Xnor:
                ofs << "xnor (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
                break;
            case Gate_Xor:
                ofs << "xor (" << g -> getName() << ", " << g -> getFanin(0) -> getName() << ", " << g -> getFanin(1) -> getName() << ");" << endl;
                break;
            default:
                break;
        }
    }
    */
    // write patch
    // FIXME: only single error, so only one patch...
    ofs << "patch p0 (";
    ofs << "." << _patch -> getPo(0) -> getName() << "(" << _F -> getError(0) -> getName() << "), ";
    max = _patch -> getPiNum() - 1;
    for(unsigned i = 0; i < _patch -> getPiNum(); ++i ) {
        ofs << "." << _patch -> getPi(i) -> getName() << "(" << _patch -> getPi(i)  -> getName() << ")" << (i == max ? ");" : ", ");
    }
    ofs << endl;
    ofs << "endmodule";
    ofs.close();
}
