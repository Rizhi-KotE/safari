#pragma once
#include "animal.h"
class GrassEater :
	public Animal
{
public:
	void eat();
	bool searchForEat(Area *);
	GrassEater(bool , string , int , int , int );
	~GrassEater();
};

