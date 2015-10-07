#pragma once
#include "stdafx.h"

using namespace std;
class Plant:
	public MapObjects
{
protected:
	string name;
	int healthPoint;
	int maxHP;
	size_t x;
	size_t y;
	int level;
public:
	Plant();
	void reproduction( Area &);
	int bitten( Animal &);
	~Plant();
	bool vitalCycle( Area &);
	void setName(string &);
	string & getName();
	void a(Animal);
	void a(Area);
	void setXY(size_t x, size_t y);
	int getX(){ return x; };
	int getY(){ return y; };
	void reborn();
	void setHP(int hp);
	int getHP(){ return healthPoint; };
	void setMaxHP(int maxHP){ this->maxHP = maxHP; };
	int getMaxHP(){ return maxHP; };
	void photoSintez();
	int getI(){ return 0; };
};
 
