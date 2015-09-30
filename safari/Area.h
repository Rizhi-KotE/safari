#pragma once
#include "stdafx.h"
#include "animal.h"
//#include <vector>

//struct cell;

using namespace std;

struct cell
{
	Plant plant;
	vector<animal> animals;
};

class Area
{
//	vector< vector < int > > area;
public:
	Area();
	~Area();
private:
	vector<vector<int>> area;
};

