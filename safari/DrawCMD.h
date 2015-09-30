#pragma once
class DrawCMD
{
	Area *area;
public:
	DrawCMD(Area &);
	void drawing();
	void drawCell(int, int);
	~DrawCMD();
};

