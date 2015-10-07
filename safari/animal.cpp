#include "stdafx.h"
#include "Animal.h"

Animal::Animal(bool gender, string name, int speedPoin)
{
	this->gender = gender;
	this->name = name;
	this->speedPoint = speedPoin;
	std::cout << "Born\n";
}
void Animal::setGender(bool gender)
{
	this->gender = gender;
}
bool Animal::getGender()
{
	return gender;
}
Animal::~Animal()
{
	std::cout << "Die\n";
}
void Animal::eat()
{
	std::cout << "OM NOM NOM\n";
}
string Animal::getName()
{
	return name;
}
/*Animal::Animal()
{
	std::cout << "born\n";
}*/

void Animal::setXYI(size_t x, size_t y, size_t i)
{
	this->x = x;
	this->y = y;
	this->i = i;
}
bool Animal::move(Area *area, int x, int y)
{
	int dX = abs(x - this->x);
	int dY = abs(y - this->y);
	double s = pow(pow(dX, 2) + pow(dY, 2), 0.5);
	if (speedPoint >= s)
	{
		if (area->changeLocateAnimal(this, x, y))
			return true;
	}
	return false;
}
bool Animal::vitalCycle(Area &area)
{
	int x = area.getAliveAnimals()->at(0)->getX();
	int y = area.getAliveAnimals()->back()->getY();
	move(&area, x, y);
	return true;
}
/*!
¬озвращает true когда звери достиг заданные координаты
*/
bool Animal::goTo(Area* area, int x, int y)
{
	if (move(area, x, y) == false)
	{
		double x0 = this->getX();
		double y0 = this->getY();
		double dX = x - x0;
		double dY = y - y0;
		double l = (double)pow(pow(dX, 2) + pow(dY, 2), 0.5);
		double cos = (double)dX / l;
		double sin = (double)dY / l;
		int deltaX = getSpeed() * cos;
		int deltaY = getSpeed() * sin;
		if (move(area, x0 + deltaX, y0 + deltaY) == true)
		/*{
			return true;
		}
		else*/ 
			return false;
	}
		return true;
}
/*!
¬озвращает true когда зверь достиг цели
*/
bool Animal::goToDestination(Area *area, MapObjects *obj)
{
	int x = obj->getX();
	int y = obj->getY();
	if(goTo(area, x, y)==true) return true;
	return false;
}
bool Animal::reproduction(Area *area)
{
	for (int i = 0; i < area->getAliveAnimals()->size();i++)
	if (area->getAliveAnimals()->at(i)->gender!=gender)
		setDestination(area->getAliveAnimals()->at(i));
		
	if (goToDestination(area,destination) == true)
	{
		Animal *child = new Animal();
		area->locateAnimal(child, x, y);
	}
	return false;
}