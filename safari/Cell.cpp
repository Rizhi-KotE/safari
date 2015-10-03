#include "stdafx.h"
#include "Cell.h"


Cell::Cell(int n)
{
		animals.resize(4);
		plant = NULL;
		this->n = n;
}


Cell::~Cell()
{
}
