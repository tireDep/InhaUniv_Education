#include "stdafx.h"
#include "Class.h"

void BasicFigure::Update(BasicFigure figure[], RECT viewRect, int cnt)
{
	int _left;
	int _top;
	int _right;
	int _bottom;

	for (int i = 0; i < cnt; i++)
	{
		_left = figure[i].point.x;
		_top = figure[i].point.y;
		_right = figure[i].point.x + figure[i].rndPos;
		_bottom = figure[i].point.y + figure[i].rndPos;

		if (_left <= viewRect.left || _right >= viewRect.right)
		{
			figure[i].movePoint.x *= -1;
		}
		else if (_top <= viewRect.top || _bottom >= viewRect.bottom)
		{
			figure[i].movePoint.y *= -1;
		}
	}
}

void BasicFigure::SetPos(int x, int y, RECT viewRect)
{
	srand((unsigned)time(NULL));

	point.x = x;
	point.y = y;
	rndPos = rand() % 150 + 1;	// 랜덤 크기 설정

	while (viewRect.right <= point.x + rndPos || viewRect.bottom <= point.y + rndPos)	// 범위 벗어날 경우 크기 재설정
	{
		rndPos = rand() % 150 + 1;
	}
}

void BasicFigure::MovePos(BasicFigure figure[], int cnt)
{
	srand((unsigned)time(NULL));
	int direction;

	for (int i = 0; i < cnt; i++)
	{
		if (movePoint.x == 0)
		{
			direction = rand() % 2;
			movePoint.x = rand() % 10 + 1;
			if (direction % 2 == 0)
				movePoint.x *= -1;

			direction = rand() % 2;
			movePoint.y = rand() % 10 + 1;
			if (direction % 2 == 0)
				movePoint.y *= -1;
		}

		figure[i].point.x += figure[i].movePoint.x;
		figure[i].point.y += figure[i].movePoint.y;
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