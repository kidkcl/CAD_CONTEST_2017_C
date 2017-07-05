// File name [ cirGate.cpp ]
#include "cir/cirGate.h" 
#include <cassert>

using namespace std;

unsigned CirGate::_globalRef = 0;

#define debug 0

/*************************
		CirGate
*************************/
/*************************
		CirConstGate
*************************/
const GateType
CirConstGate::getType() const
{
	return Gate_Const;
}

void
CirConstGate::report() const
{
	if( _name == "1'b0" ) cout << "[Const0]";
	else cout << "[Const1]";
}

void
CirConstGate::addToSolver(SatSolverV* s) const
{
	if( debug ) {
		if( _name == "1'b0" ) std::cout << "add const0 CNF" << std::endl;
		else std::cout << "add const1 CNF" << std::endl;
	}
	//if( _name == "1'b0" ) s -> addUnitCNF(_var, false);
	//else s -> addUnitCNF(_var, true);
}
/*************************
		CirPiGate
*************************/
const GateType
CirPiGate::getType() const
{
	return Gate_Pi;
}

void
CirPiGate::report() const
{
	cout << "[Pi]: " << _name;
}

void
CirPiGate::addToSolver(SatSolverV* s) const
{
	if( debug ) {
		std::cout << "add Pi CNF, do nothing" << std::endl;
	}
}
/*************************
		CirPoGate
*************************/
const GateType
CirPoGate::getType() const
{
	return Gate_Po;
}

void
CirPoGate::report() const
{
	cout << "[Po]: " << _name;
}

void
CirPoGate::addToSolver(SatSolverV* s) const
{
	assert(_in.size() == 1);
	if( debug ) {
		std::cout << "add Po CNF:" << std::endl;
	}
	s -> addEqCNF(_var, getFaninVar(0), isFaninInv(0));	
}
/*************************
		CirBufGate
*************************/
const GateType
CirBufGate::getType() const
{
	return Gate_Buf;
}

void
CirBufGate::report() const
{
	cout << "[Buf]: " << _name;
}

void
CirBufGate::addToSolver(SatSolverV* s) const
{
	assert(_in.size() == 1);
	if( debug ) {
		std::cout << "add Buf CNF:" << std::endl;
	}
	s -> addEqCNF(_var, getFaninVar(0), isFaninInv(0));
}
/*************************
		CirInvGate
*************************/
const GateType
CirInvGate::getType() const
{
	return Gate_Inv;
}

void
CirInvGate::report() const
{
	cout << "[Inv]: " << _name;
}

void
CirInvGate::addToSolver(SatSolverV* s) const
{
	assert(_in.size() == 1);
	if( debug ) {
		std::cout << "add Inv CNF:" << std::endl;
	}
	s -> addEqCNF(_var, getFaninVar(0), !isFaninInv(0));
}
/*************************
		CirAndGate
*************************/
const GateType
CirAndGate::getType() const
{
	return Gate_And;
}

void
CirAndGate::report() const
{
	cout << "[And]: " << _name;
}

void
CirAndGate::addToSolver(SatSolverV* s) const
{
/*	Lit outLit = mkLit(_id, false);
	vec<Lit> c;
	c.push(outLit);
	for( unsigned i = 0; i < _in.size(); ++i ) {
		Lit inLit = mkLit(getFaninId(0), isFaninInv(0));
		c.push(~inLit);
		// (in[i] + ~out)
		s -> addClause(inLit, ~outLit);	
	}
	// (out + ~in[0] + ~in[1] + ...)
	s -> addClause(c);
*/
	assert(_in.size() == 2);
	if( debug ) {
		std::cout << "add And CNF:" << std::endl;
	}
	s -> addAndCNF(_var, getFaninVar(0), isFaninInv(0), getFaninVar(1), isFaninInv(1));	
}
/*************************
		CirOrGate
*************************/
const GateType
CirOrGate::getType() const
{
	return Gate_Or;
}

void
CirOrGate::report() const
{
	cout << "[Or]: " << _name;
}

void
CirOrGate::addToSolver(SatSolverV* s) const
{
/*
	Lit outLit = mkLit(_id, false);
	vec<Lit> c;
	c.push(~outLit);
	for( unsigned i = 0; i < _in.size(); ++i ) {
		Lit inLit = mkLit(getFaninId(0), isFaninInv(0));
		c.push(inLit);
		// (~in[i] + out)
		s -> addClause(~inLit, outLit);	
	}
	// (~out + in[0] + in[1] + ...)
	s -> addClause(c);
*/
	assert(_in.size() == 2);
	if( debug ) {
		std::cout << "add Or CNF:" << std::endl;
	}
	s -> addOrCNF(_var, getFaninVar(0), isFaninInv(0), getFaninVar(1), isFaninInv(1));
}
/*************************
		CirNandGate
*************************/
const GateType
CirNandGate::getType() const
{
	return Gate_Nand;
}

void
CirNandGate::report() const
{
	cout << "[Nand]: " << _name;
}

void
CirNandGate::addToSolver(SatSolverV* s) const
{
	assert(_in.size() == 2);
	if( debug ) {
		std::cout << "add Nand CNF:" << std::endl;
	}
	s -> addOrCNF(_var, getFaninVar(0), !isFaninInv(0), getFaninVar(1), !isFaninInv(1));
}
/*************************
		CirNorGate
*************************/
const GateType
CirNorGate::getType() const
{
	return Gate_Nor;
}

void
CirNorGate::report() const
{
	cout << "[Nor]: " << _name;
}

void
CirNorGate::addToSolver(SatSolverV* s) const
{
	assert(_in.size() == 2);
	if( debug ) {
		std::cout << "add Nor CNF:" << std::endl;
	}
	s -> addAndCNF(_var, getFaninVar(0), !isFaninInv(0), getFaninVar(1), !isFaninInv(1));
}
/*************************
		CirXorGate
*************************/
const GateType
CirXorGate::getType() const
{
	return Gate_Xor;
}

void
CirXorGate::report() const
{
	cout << "[Xor]: " << _name;
}

void
CirXorGate::addToSolver(SatSolverV* s) const
{
	assert(_in.size() == 2);
	if( debug ) {
		std::cout << "add Xor CNF:" << std::endl;
	}
	s -> addXorCNF(_var, getFaninVar(0), isFaninInv(0), getFaninVar(1), isFaninInv(1));
}
/*************************
		CirXnorGate
*************************/
const GateType
CirXnorGate::getType() const
{
	return Gate_Xnor;
}

void
CirXnorGate::report() const
{
	cout << "[Xnor]: " << _name;
}

void
CirXnorGate::addToSolver(SatSolverV* s) const
{
	assert(_in.size() == 2);
	if( debug ) {
		std::cout << "add Xnor CNF:" << std::endl;
	}
	s -> addXnorCNF(_var, getFaninVar(0), isFaninInv(0), getFaninVar(1), isFaninInv(1));
}
/*************************
		CirErrorGate
*************************/
const GateType
CirErrorGate::getType() const
{
	return Gate_Error;
}

void
CirErrorGate::report() const
{
	cout << "[Error]: " << _name;
}

void
CirErrorGate::addToSolver(SatSolverV* s) const
{
    assert(_in.size() < 2);
	if( debug ) {
		if( _in.size() == 0 ) std::cout << "add Error CNF: do nothing before patch" << std::endl;
		else std::cout << "add Error CNF: after patching" << std::endl;
	}
    if(_in.size() == 0) return;
    s -> addEqCNF(_var, getFaninVar(0), isFaninInv(0));
}
/*************************
		CirMuxGate
*************************/
const GateType
CirMuxGate::getType() const
{
	return Gate_Mux;
}

void
CirMuxGate::report() const
{
	cout << "[Mux]: " << _name;
}

void
CirMuxGate::addToSolver(SatSolverV* s) const
{
	// TODO
	assert(_in.size() == 3);
	if( debug ) {
		std::cout << "add Mux CNF:" << std::endl;
	}
	s -> addMuxCNF(_var, getFaninVar(0), isFaninInv(0), getFaninVar(1), isFaninInv(1), getFaninVar(2), isFaninInv(2));	
}
