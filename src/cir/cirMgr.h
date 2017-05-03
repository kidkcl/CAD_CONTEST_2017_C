// File name [ cirMgr.h ]
#ifndef CIRMGR_H
#define CIRMGR_H

#include <iostream>
#include <string>

#include "cir/cirNet.h"
#include "minisat/Solver.h"

using namespace std;

class CirMgr
{
public:
	explicit CirMgr(const string& name = ""): _name(name), _F(NULL), _G(NULL), _patch(NULL) { _s = new SatSolver; }
	~CirMgr() {}//{ delete _F; delete _G; delete _patch; }

//	info
	void setName(const string& n ) 	{ _name = n; }
	CirNet* getF() 					{ return _F; }
	CirNet* getG() 					{ return _G; }
	CirNet* getPath() 				{ return _patch; }

//	in cirParse.cpp
	bool readVerilog(const string& filename, bool isF);
	bool removeComment(const string& inFileName, const string& outFileName) const;

//	in cirDup.cpp
	CirNet* dupNet(CirNet* n) const;
	CirNet* connectXor(CirNet* f, CirNet* g);

//  test
	void test();

private:
	string 								_name;
	CirNet*								_F;
	CirNet*								_G;
	CirNet*								_dupF;
	CirNet*								_dupG;
	CirNet*								_patch;
	SatSolver*							_s;
};

#endif
