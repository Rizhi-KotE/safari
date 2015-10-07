#pragma once
#include "stdafx.h"
#include "MapObjects.h"
using namespace std;

class Plant;
class Area;
class MapObject;

class Animal:
	public MapObjects
{
protected:
	int healthPoint;
	int maxHP;
	bool gender;
	string name;
	int level;
	int x;
	int y;
	int i;
	int speedPoint;
	MapObjects *destination;
	int energy = 100;
	int maxEnergy = 100;
public:
	//Animal();
	Animal(bool gender = true, string name = "animal", int speedPoint = 3);
	void setGender(bool gender);
	bool getGender();
	void eat();
	void talk();
	~Animal();
	string getName();
	bool reproduction(Area *);
	void a(Area);
	void setXYI(size_t x, size_t y, size_t i);
	int getX(){ return x; };
	int getY(){ return y; };
	void setHP(int hp);
	int getHP(){ return healthPoint; };
	void setMaxHP(int maxHP){ this->maxHP = maxHP; };
	int getMaxHP(){ return maxHP; };
	bool move(Area*, int x, int y);
	bool goTo(Area*, int x, int y);
	void setI(int i){ this->i = i; };
	int getI() { return i; };
	bool vitalCycle(Area &);
	int getSpeed(){ return speedPoint; };
	bool goToDestination(Area *,MapObjects *);
	void setDestination(MapObjects *destination){ this->destination = destination; };
	void setEnergy(int energy){ this->energy = energy; };
	int getEnergy(){ return energy; };
	void setmaxMaxEnergy(int maxEnergy){ this->maxEnergy = maxEnergy; };
	int getMaxEnergy(){ return maxEnergy; };
	bool searchForEat(Area *){ return true; };
	bool searchForFamily(Area *){ return true; };
};



