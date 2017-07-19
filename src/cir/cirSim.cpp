// File name [ cirSim.cpp ]

#include <iostream>
#include <vector>
#include <bitset>

#include "cir/cirMgr.h"

void
CirMgr::knownSim(CirNet* g, CirNet* f) const
{
	assert(g -> getPiNum() == f -> getPiNum()); assert(g -> getPoNum() == f -> getPoNum());
	// tie PI simV
	for( unsigned i = 0; i < f -> getPiNum(); ++i ) {
		g -> getPi(i) -> setSimV(f -> getPi(i) -> getSimV());
	}
	g -> knownSim();
}

void
CirMgr::analyzeVec(std::vector<size_t>& t_1, std::vector<size_t>& t_0)
{
	for( unsigned i = 0; i < 32; ++i ) {
		bool goodVec = true;
		size_t filter = 0x1 << i;
		//std::cout << "filter: " << std::bitset<32>(filter) << std::endl;
		for( unsigned j = 0; j < _F -> getPoNum(); ++j ) {
			if( (_F -> getPo(j) -> getSimV() & filter) ^ (_G -> getPo(j) -> getSimV() & filter) ) { goodVec = false; break; }
		}
		std::cout << "[" << i << "]: " << goodVec << ", error: " << (bool)(_F -> getError(0) -> getSimV() & filter) << std::endl;
		// construct assignment for each candidate (assume all)
		size_t assignment = 0;
		for( unsigned j = 0; j < _sortedCandGate.size(); ++j ) {
			if( _sortedCandGate[j] -> getSimV() & filter ) assignment |= (0x1 << j);
		}
		//std::cout << "assignment: " << std::bitset<32>(assignment) << std::endl;
		if( goodVec ) {
			// assume single error
			if( _F -> getError(0) -> getSimV() & filter ) t_1.push_back(assignment);
			else t_0.push_back(assignment);
		}
		else {
			if( _F -> getError(0) -> getSimV() & filter ) t_0.push_back(assignment);
			else t_1.push_back(assignment);
		}
	}
}
