#include "stdafx.h"
#include "GrassEater.h"


GrassEater::GrassEater(bool gender = true, string name = "animal", int speedPoint = 3,
	int energy = 100, int maxEnergy = 100)
{
	this->gender = gender;
	this->name = name;
	this->speedPoint = speedPoint;
	this->energy = energy;
	this->maxEnergy = maxEnergy;

}


GrassEater::~GrassEater()
{
}

void eat()
{

}