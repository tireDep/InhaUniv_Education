#include "stdafx.h"
#include "Class.h"

void BasicFigure::SetPos(int x, int y, RECT viewRect)
{
	srand((unsigned)time(NULL));

	point.x = x;
	point.y = y;
	rndPos = rand() % 250 + 1;	// 랜덤 크기 설정

	while (viewRect.right <= point.x + rndPos || viewRect.bottom <= point.y + rndPos)	// 범위 벗어날 경우 크기 재설정
	{
		rndPos = rand() % 250 + 1;
	}
}

int BasicFigure::GetPosX()
{
	return point.x;
}

int BasicFigure::GetPosY()
{
	return point.y;
}

int BasicFigure::GetPosRnd()
{
	return rndPos;
}