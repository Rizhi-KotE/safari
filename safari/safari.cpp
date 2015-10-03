// safari.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"



int _tmain(int argc, _TCHAR* argv[])
{
	//Animal a = Animal();
	Plant *z = new Plant();
    Area area = Area(3, 3);
	area.setPlant(z, 1, 1);
	DrawCMD drawer = DrawCMD(area);
	while (true)
	{
		drawer.drawing();
		for (int i = 0; i < area.getAlivePlant()->size(); i++)
		{
			if (area.getAlivePlant()->at(i)->vitalCycle(area) == true)
				area.plantDied(i);
		}
 		system("pause");
	}
	
	return 0;
}

