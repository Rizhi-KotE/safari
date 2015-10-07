#include "stdafx.h"
#include "Plant.h"
/*!
Растение создает такоеже растение в соседней случайной клетке,
или полностью востанавливает свойю энергию
param[in] area ссылка на клас зоны
*/
void Plant::reproduction( Area &area)
{
	int bl = rand() % 2;
	if (bl == 0)
	{
		int dX = (rand() % 3) - 1;
		int dY = (rand() % 3) - 1;
		Plant *tmp = new Plant();
		area.setPlant(tmp, x + dX, y + dY);
	}
}
/*!
Конструктор класса
*/
Plant::Plant()
{
	maxHP=healthPoint = 20;
	name = "Plant";
	//std::cout << "Plant born\n";
}
/*!
Деструктор
*/
Plant::~Plant()
{
	//std::cout << "Die plant\n";
}
/*!
Жизненный цикл растения: размножение и трата очков здоровья
param[in] area
*/
bool Plant::vitalCycle(Area & area)
{
	bool alive = true;
	reproduction(area);
	photoSintez();
	healthPoint -= (int)maxHP*0.5;
	return (healthPoint <= 0 ? true : false);
}
/*!
Устанавливает координаты находения растения
param[in] x столбец
param[in] y строка*/
void Plant::setXY(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
}
/*!
Возвращает имя растения
param[out] name
*/
string & Plant::getName()
{
	return name;
}
/*!
Устанавливает очки энергии растения в максимальное значение*/
void Plant::reborn()
{
	healthPoint = maxHP;
}
/*!
Устанавливает новое имя расстения
param[in] name
*/
void Plant::setName(string &name)
{
	this->name = name;
}
/*
Устанавливает текущее значение энергии, учитывает максимальное значение
param[in] hp
*/
void Plant::setHP(int hp)
{
	if (hp >= 0)
	{
		if (hp < maxHP)
			healthPoint = hp;
		else healthPoint = maxHP;
	}
}
/*!
востанавливает энергию растения
*/
void Plant::photoSintez()
{
	setHP(healthPoint + (int)healthPoint*0.5);
}