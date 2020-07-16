#include "stdafx.h"
#include "FigureShape.h"

cCircle::cCircle()
{
	for (int i = 0; i < 2; i++)
	{
		circlePos[i].x = 0;
		circlePos[i].y = 0;
	}
	SetFigureShape(0);
};

cCircle::cCircle(int posx, int posy)
{
	srand((unsigned)time(NULL));
	int rndpos = rand() % 100 + 10;

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			circlePos[i].x = posx;
			circlePos[i].y = posy;
		}
		else
		{
			circlePos[i].x = posx + rndpos;
			circlePos[i].y = posy + rndpos;
		}
	}

	SetPosRnd(rndpos);
	SetRadius((double) rndpos / 2);
	SetFigureShape(0);
};

cCircle::~cCircle() 
{

};

void cCircle::DrawFigureShape(HDC hdc)
{
	Ellipse(hdc, circlePos[0].x, circlePos[0].y, circlePos[1].x, circlePos[1].y);
}

void cCircle::MovePos()
{
	BasicFigure::MovePos();
	POINT _movePos = GetMovePos();
	for (int i = 0; i < 2; i++)
	{
		this->circlePos[i].x += _movePos.x;
		this->circlePos[i].y += _movePos.y;
	}
}