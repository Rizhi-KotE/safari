#pragma once
class Cell
{
	int maxAni = 4;
public:
	Cell(int maxAni = 4);
	~Cell();
	int getMaxAni(){ return maxAni; };
	Plant *plant;
	vector <Animal*> animals;
};

