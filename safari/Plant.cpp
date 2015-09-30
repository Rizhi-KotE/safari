#include "stdafx.h"
#include "Plant.h"

void Plant::reproduction( Area &area)
{
	bool bl = rand() % 2;
	if (bl == true)
	{
		int dX = (rand() % 3) - 1;
		int dY = (rand() % 3) - 1;
		Plant tmp = Plant();
		area.setPlant(tmp, x + dX, y + dY);
	}
}

Plant::Plant()
{
	name = "Plant";
}


Plant::~Plant()
{
	std::cout << "Die plant\n";
}
bool Plant::vitalCycle(Area & area)
{
	//bool alive = true;
	reproduction(area);
	healthPoint--;
	return (bool)healthPoint;
}
void Plant::setXY(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
}
string & Plant::getName()
{
	return name;
}