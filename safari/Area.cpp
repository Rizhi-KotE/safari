#include "stdafx.h"
#include "Area.h"



/*!
������ ������ Plant � ������ �������� ����,
������������� ���������� �������� � ��������� �������� � ������ ����� ��������
\param[in] plant ������ �� ��������� ������ Plant
\param[in] x ����� ������ �������� ����
\param[in] y ����� ������� �������� ����
*/

void Area::setPlant(Plant *plant, int x, int y)
{
	if ((x < area.size()) && (x >= 0))
	if ((y < area[x].size()) && (y >= 0))
	{
		if (this->area[x][y].plant == NULL){
			this->area[x][y].plant = plant;
			plant->setXY(x, y);
			this->alivePlant.push_back(plant);
		}
		else
		{
			this->area[x][y].plant->reborn();
		}
	}
}

/*!
������� ���� x*y
param[in] x ���������� ����� 
param[in] y ���������� ��������
*/
Area::Area(int x, int y)
{
	for (size_t i = 0; i < x; i++)
	{
		vector<Cell > row;
		//row.resize(y);
		for (int j = 0; j < y; j++)
		{
			Cell c = Cell(j);
			row.push_back(c);
		}
		area.push_back(row);
	}
}

Area::~Area()
{
}
/*!
���������� ��������� �� ��������, ����������� �
������ x*y
*/
Plant* Area::getPlant(int x, int y)
{
	return area[x][y].plant;
}
/*!
���������� ������� ��������
*/
void Area::plantDied(int j)
{
	int x = this->alivePlant[j]->getX();
	int y = this->alivePlant[j]->getY();
 	this->alivePlant[j]->~Plant();
	area[x][y].plant = NULL;
	this->alivePlant.erase(alivePlant.begin() + j);	
}
 vector<vector<Cell >> Area::getArea()
{
	return this->area;
}
vector<Animal *> Area::getAnimals(int x, int y)
{
	return area[x][y].animals;
}
vector<Plant *> * Area::getAlivePlant()
{ return &alivePlant; }