#pragma once
#include "stdafx.h"

using namespace std;
class Plant
{
protected:
	string name;
	int healthPoint;
	int maxHP;
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
	int getX(){ return x; };
	int getY(){ return y; };
	void reborn();
};
 
