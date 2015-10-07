#pragma once
#include "stdafx.h"

class Cell;

class Area
{
private:
	vector<vector<Cell>> area;
	vector<Animal *> aliveAnimals;
	vector<Plant *> alivePlant;
	unsigned int time = 0;
public:
	void setPlant(Plant *, int ,int);
	Plant * getPlant(int, int);
	void plantDied(int);
	Area(int x = 0, int y = 0);
	~Area();
	void a(Animal);
	vector<vector<Cell >> getArea();
	vector<Animal *> getAnimals(int x = 0, int y = 0);
	vector<Plant *> *getAlivePlant();
	vector<Animal *> *getAliveAnimals();
	void plantsLife();
	void animalsLife();
	bool locateAnimal(Animal *, int, int);
	bool changeLocateAnimal(Animal *, int, int);
	void animalDied(int);
	void setTime(unsigned int time){ this->time = time; }
	unsigned int getTime(){ return time; };

};
