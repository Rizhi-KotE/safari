#include "stdafx.h"
#include "Cell.h"


Cell::Cell(int maxAni)
{
		animals.reserve(4);
		plant = NULL;
		this->maxAni = maxAni;
}


Cell::~Cell()
{
}
