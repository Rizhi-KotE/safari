#pragma once
class Cell
{

public:
	Cell(int n = 0);
	~Cell();
	Plant *plant;
	vector <Animal*> animals;
	int n;
};

