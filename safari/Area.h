#pragma once
#include "stdafx.h"


class Cell;

class Area
{
private:
	vector<vector<Cell *>> area;
	vector<Animal *> aliveAnimals;
	vector<Plant *> alivePlant;
public:
	void setPlant(Plant &, int ,int);
	Plant getPlant(int, int);
	void plantDied(int, int);
	Area(int x = 0, int y = 0);
	~Area();
	void a(Animal);
	void a(Plant);
	vector<vector<Cell *>> getArea();
	vector<Animal *> getAnimals(int x = 0, int y = 0);
};
