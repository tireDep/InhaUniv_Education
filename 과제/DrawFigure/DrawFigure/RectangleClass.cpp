#include "stdafx.h"
#include "FigureShape.h"

cRect::cRect()
{
	for (int i = 0; i < 2; i++)
	{
		rectPos[i].x = 0;
		rectPos[i].y = 0;
	}
	SetFigureShape(4);
};

cRect::cRect(int posx, int posy)
{
	srand((unsigned)time(NULL));
	int rndpos = rand() % 100 + 10;

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			rectPos[i].x = posx;
			rectPos[i].y = posy;
		}
		else
		{
			rectPos[i].x = posx + rndpos;
			rectPos[i].y = posy + rndpos;
		}
	}

	SetPosRnd(rndpos);
	SetRadius((double)rndpos / 2);
	SetFigureShape(4);
};

cRect::~cRect() 
{ 

};

void cRect::DrawFigureShape(HDC hdc)
{
	Rectangle(hdc, rectPos[0].x, rectPos[0].y, rectPos[1].x, rectPos[1].y);
}

void cRect::MovePos()
{
	BasicFigure::MovePos();
	POINT _movePos = GetMovePos();
	for (int i = 0; i < 2; i++)
	{
		this->rectPos[i].x += _movePos.x;
		this->rectPos[i].y += _movePos.y;
	}
}