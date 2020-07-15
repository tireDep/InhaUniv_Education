#include "stdafx.h"
#include "Class.h"

void cRect::DrawFigure(HDC hdc)
{
	int _x = GetPosX();
	int _y = GetPosY();
	int _rnd = GetPosRnd();

	// Ellipse(hdc, _x, _y, _x + _rnd, _y + _rnd);	// 마우스 좌표에 도형 생성
	Rectangle(hdc, _x, _y, _x + _rnd, _y + _rnd);
}