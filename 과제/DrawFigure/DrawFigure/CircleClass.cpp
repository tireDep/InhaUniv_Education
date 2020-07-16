#include "stdafx.h"
#include "FigureShape.h"

cCircle::cCircle()
{
	circlePos.x = 0;
	circlePos.y = 0;
	SetFigureShape(0);
};

cCircle::cCircle(int posx, int posy)
{
	srand((unsigned)time(NULL));
	int rndpos = rand() % 100 + 10;

	circlePos.x = posx;
	circlePos.y = posy;

	SetPosRnd(rndpos);
	SetFigureShape(0);
};

cCircle::~cCircle() { };

void cCircle::DrawFigure(HDC hdc)
{
	int _rnd = GetPosRnd();
	Ellipse(hdc, circlePos.x, circlePos.y, circlePos.x + _rnd, circlePos.y + _rnd);
}

void cCircle::MovePos()
{
	BasicFigure::MovePos();
	POINT _movePos = GetMovePos();
	this->circlePos.x += _movePos.x;
	this->circlePos.y += _movePos.y;
}