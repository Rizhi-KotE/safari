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
			Cell c = Cell();
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
/*!
обрабатывает жизненный цикл у всех живых растений
*/
void Area::plantsLife()
{
	int plantsValue = getAlivePlant()->size();
	for (int i = 0; i < plantsValue; i++)
	{
		getAlivePlant()->at(i)->vitalCycle(*this);
	}
	for (int i = 0; i < plantsValue; i++)
	{
		if (getAlivePlant()->at(i)->getHP() <= 0)
		{
			plantDied(i);
			i--;
			plantsValue--;
		}
	}
}
void Area::animalsLife()
{
	int AnimalsValue = getAliveAnimals()->size();
	for (int i = 0; i < AnimalsValue; i++)
	{
		//getAliveAnimals()->at(i)->vitalCycle(*this);
	}
	for (int i = 0; i < AnimalsValue; i++)
	{
		if (getAliveAnimals()->at(i)->getHP() <= 0)
		{
			//AnimalDied(i);
			i--;
			AnimalsValue--;
		}
	}
}
bool Area::locateAnimal(Animal *ani, int x, int y)
{
	if ((x < area.size()) && (x >= 0))
	if ((y < area[x].size()) && (y >= 0))
	{
		if (area[x][y].animals.size() < area[x][y].getMaxAni()){
			area[x][y].animals.push_back(ani);
			ani->setXYI(x, y, area[x][y].animals.size() - 1);
			this->aliveAnimals.push_back(ani);
			return true;
		}
	}
	return false;
}
vector<Animal *> *Area::getAliveAnimals()
{
	return &aliveAnimals;
}
bool Area::changeLocateAnimal(Animal *ani, int x, int y)
{
	if ((x < area.size()) && (x >= 0))
	if ((y < area[x].size()) && (y >= 0))
	{
		if (area[x][y].animals.size() < area[x][y].getMaxAni()){
			area[ani->getX()][ani->getY()].animals.erase(area[ani->getX()][ani->getY()].animals.begin() + ani->getI());
			ani->setI(area[x][y].animals.size());
			area[x][y].animals.push_back(ani);
			ani->setXYI(x, y, area[x][y].animals.size() - 1);
			return true;
		}
	}
	return false;
}
void Area::animalDied(int j)
{
	int x = this->aliveAnimals[j]->getX();
	int y = this->aliveAnimals[j]->getY();
	int i = this->aliveAnimals[j]->getI();
 	this->alivePlant[j]->~Plant();
	area[x][y].animals.erase(area[x][y].animals.begin() + i);
	this->alivePlant.erase(alivePlant.begin() + j);	
}