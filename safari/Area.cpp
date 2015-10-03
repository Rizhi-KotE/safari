#include "stdafx.h"
#include "Area.h"



/*!
Ставит объект Plant в клетку игрового поля,
устанавливает координаты растения и сохраняет растение в список живых растений
\param[in] plant ссылка на экземпляр класса Plant
\param[in] x номер строки игрового поля
\param[in] y номер столбца игрового поля
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
Создает поле x*y
param[in] x количество строк 
param[in] y количество столбцов
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
Возвращает указатель на растение, находящееся в
клетке x*y
*/
Plant* Area::getPlant(int x, int y)
{
	return area[x][y].plant;
}
/*!
Уничтожает мертвое растение
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