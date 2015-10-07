// safari.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define male true
#define female false



int _tmain(int argc, _TCHAR* argv[])
{
	thread brush = thread();
	//Animal a = Animal();
	Animal *mani = new Animal(female, "animal", 2);
	Plant *z = new Plant();
    Area area = Area(3, 8);
	MapObjects *obj = mani;
	z = (Plant *)obj;
	cout << z->getName() << endl;
	Animal *ani = new Animal(male,"animal",2);

	
	area.setPlant(z, 1, 1);
	area.locateAnimal(ani, 0, 0);
	area.locateAnimal(mani, 2, 7);
	//area.animalDied(0);
	DrawCMD drawer = DrawCMD(area);
	while (true)
	{
		
		//brush.join();
		drawer.drawing();
		area.plantsLife();
		ani->reproduction(&area);
		mani->reproduction(&area);
		area.setTime(area.getTime() + 1);
		//ani->vitalCycle(area);
		/*if (area.getAlivePlant()->size() > 0){
			MapObjects *obj = area.getAlivePlant()->at(0);
			ani->goToDestination(&area, obj);
		}*/
		system("pause");
	}
	
	return 0;
}

