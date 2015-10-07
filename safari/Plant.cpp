#include "stdafx.h"
#include "Plant.h"
/*!
�������� ������� ������� �������� � �������� ��������� ������,
��� ��������� �������������� ����� �������
param[in] area ������ �� ���� ����
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
����������� ������
*/
Plant::Plant()
{
	maxHP=healthPoint = 20;
	name = "Plant";
	//std::cout << "Plant born\n";
}
/*!
����������
*/
Plant::~Plant()
{
	//std::cout << "Die plant\n";
}
/*!
��������� ���� ��������: ����������� � ����� ����� ��������
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
������������� ���������� ��������� ��������
param[in] x �������
param[in] y ������*/
void Plant::setXY(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
}
/*!
���������� ��� ��������
param[out] name
*/
string & Plant::getName()
{
	return name;
}
/*!
������������� ���� ������� �������� � ������������ ��������*/
void Plant::reborn()
{
	healthPoint = maxHP;
}
/*!
������������� ����� ��� ���������
param[in] name
*/
void Plant::setName(string &name)
{
	this->name = name;
}
/*
������������� ������� �������� �������, ��������� ������������ ��������
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
�������������� ������� ��������
*/
void Plant::photoSintez()
{
	setHP(healthPoint + (int)healthPoint*0.5);
}