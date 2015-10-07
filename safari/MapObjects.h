#pragma once
class MapObjects
{
public:
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getI() = 0;
	MapObjects();
	virtual ~MapObjects();
};

