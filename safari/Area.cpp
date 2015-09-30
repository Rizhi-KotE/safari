#include "stdafx.h"
#include "Area.h"

class Cell
{
public:
	Plant *plant;
	vector <Animal*> animals;
	Plant i;
	Cell(){
		animals.resize(4);
		i = Plant();
		plant = &Plant();
		for (int i = 0; i < 4; i++)
			animals[i] = &Animal();

	}
};


/*!
������ ������ Plant � ������ �������� ����,
������������� ���������� �������� � ��������� �������� � ������ ����� ��������
\param[in] plant ������ �� ��������� ������ Plant
\param[in] x ����� ������ �������� ����
\param[in] y ����� ������� �������� ����
*/

void Area::setPlant(Plant &plant, int x, int y)
{
	if ((x < area.size()) && (x >= 0))
	if ((y < area[x].size()) && (y >= 0))
	{
		area[x][y]->plant = &plant;
		plant.setXY(x, y);
		alivePlant.push_back(&plant);
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
		vector<Cell *> row;
		row.resize(y);
		for (int i = 0; i < y; i++)
			row[i] = &Cell();
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
Plant Area::getPlant(int x, int y)
{
	return *area[x][y]->plant;
}
/*!
���������� ������� ��������
*/
void Area::plantDied(int x, int y)
{
	area[x][y]->plant->~Plant();
	area[x][y]->plant = NULL;
}
 vector<vector<Cell *>> Area::getArea()
{
	return this->area;
}
vector<Animal *> Area::getAnimals(int x, int y)
{
	return area[x][y]->animals;
}