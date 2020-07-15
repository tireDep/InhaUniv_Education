#include "stdafx.h"
#include "Class.h"

void cRect::DrawFigure(HDC hdc)
{
	int _x = GetPosX();
	int _y = GetPosY();
	int _rnd = GetPosRnd();

	Rectangle(hdc, _x, _y, _x + _rnd, _y + _rnd);
}



void cRect::Rotation()
{

}