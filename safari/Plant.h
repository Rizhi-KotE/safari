#pragma once
#include "stdafx.h"

using namespace std;
class Plant
{
protected:
	string name;
	int healthPoint;
	size_t x;
	size_t y;
public:
	Plant();
	void reproduction( Area &);
	int bitten( Animal &);
	~Plant();
	bool vitalCycle( Area &);
	void setXY(size_t x, size_t y);
	string & getName();
	void a(Animal);
	void a(Area);
};
 
