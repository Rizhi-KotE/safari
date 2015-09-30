// safari.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{

    Area area(3,3);// = Area(3, 3);
	area.setPlant(Plant(), 1, 1);
	DrawCMD drawer = DrawCMD(area);
	while (true)
	{
		drawer.drawing();
		area.getPlant(1, 1).vitalCycle(area);
		system("pause");
	}
	
	return 0;
}

