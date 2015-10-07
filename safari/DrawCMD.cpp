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
	system("cls");
	int x = area->getArea().size();
	int y = area->getArea()[0].size();
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++)
		{
			cout << setw(8) << "|------|";
		}
		cout << endl;
		{
			for (int j = 0; j < y; j++)
				cout << "|" << setw(6) << (area->getPlant(i,j) == NULL ?  "" : area->getPlant(i, j)->getName()) << "|";
			cout << endl;
		}
		for (int z = 0; z < 4; z++)
		{
			for (int j = 0; j < y; j++)
				cout << "|" << setw(6) << (z < area->getAnimals(i, j).size() ? area->getAnimals(i, j)[z]->getName() : "")
					<< "|";
			cout << endl;
		}
		for (int j = 0; j < y; j++)
		{
			cout << setw(8) << "|------|";
		}
		cout << endl;
	}
	/*string s;
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++)
		{
			s+="|------|";
		}
		s+="\n";
		{
			for (int j = 0; j < y; j++)
			{
				s += "|";
				s += (area->getPlant(i, j) == NULL ? "      " : area->getPlant(i, j)->getName()+" ");
				s += "|";
			}
			s += "\n";
		}
		for (int z = 0; z < 4; z++)
		{
			for (int j = 0; j < y; j++)
			{
				s += "|";
				s += (z < area->getAnimals(i, j).size() ? area->getAnimals(i, j)[z]->getName() : "      ");
				s += "|";
			}
			s += "\n";
		}
		for (int j = 0; j < y; j++)
		{
			s += "|------|";
		}
		s += "\n";
	}
	cout << s << endl;*/
}