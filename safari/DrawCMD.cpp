#include "stdafx.h"
#include "DrawCMD.h"

using namespace std;

DrawCMD::DrawCMD(Area &area)
{
	this->area = &area;
}
DrawCMD::~DrawCMD()
{
}
void DrawCMD::drawing()
{
	int x = area->getArea().size();
	int y = area->getArea()[0].size();
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++)
		{
			cout << setw(8) << "|------|";
		}
		{
			for (int j = 0; j < y; j++)
				cout << "|" << setw(6) << area->getPlant(x,y).getName() << "|";
			cout << endl;
		}
		for (int z = 0; z < 4; z++)
		{
			for (int j = 0; j < y; j++)
				cout << "|" << setw(6) << area->getAnimals(i, j)[z].getName() << "|" ;
			cout << endl;
		}
		for (int j = 0; j < y; j++)
		{
			cout << setw(8) << "|------|";
		}
	}
}
void DrawCMD::drawCell(int x, int y)
{
	cout << setw(8) << "|------|\n";
	cout << "|" << setw(6) << area->getPlant(x, y).getName() << "|" << endl;
	for (int i = 0; i < 4; i++)
		cout << "|" << setw(6) << area->getAnimals(x, y)[i].getName() << "|" << endl;
	cout << setw(8) << "|------|\n";
}