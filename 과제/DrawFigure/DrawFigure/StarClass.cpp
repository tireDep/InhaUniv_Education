#include "stdafx.h"
#include "FigureShape.h"

cStar::cStar()
{
	for (int i = 0; i < 10; i++)
	{
		starPos[i].x = 0;
	}

	SetFigureShape(5);
};

cStar::cStar(int posx, int posy)
{
	srand((unsigned)time(NULL));

	int rndpos = rand() % 100 + 10;

	POINT temp[5] = { 0 };
	temp[0].x = posx;
	temp[0].y = posy - rndpos;
	AddPoint(posx, posy, temp);

	// 크래머 공식
	double a, b, c, d, e, f;
	int _posX, _posY;

	a = temp[0].y - temp[2].y;
	b = -(temp[0].x - temp[2].x);
	e = a*temp[0].x + b*temp[0].y;

	c = temp[1].y - temp[4].y;
	d = -(temp[1].x - temp[4].x);
	f = c*temp[1].x + d*temp[1].y;

	double divide = (a*d) - (b*c);
	_posX = ((e*d) - (b*f)) / divide;
	_posY = ((a*f) - (e*c)) / divide;
	// 크래머 공식

	POINT temp2[5] = { 0 };
	temp2[0] = { _posX, _posY };
	AddPoint(posx, posy, temp2);

	// 좌표 저장
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		starPos[i] = temp[j];
		starPos[++i] = temp2[j++];
	}

	SetPosRnd(rndpos);
	SetRadius((double)rndpos / 2);
	SetFigureShape(5);
};

cStar::~cStar()
{

};

void cStar::AddPoint(int posx, int posy, POINT calcP[])
{
	int degree = 72;
	int addDegree = degree;
	double radian;
	int tempX, tempY;

	for (int i = 1; i < 5; i++)
	{
		radian = degree *(M_PI / 180);
		degree += addDegree;

		tempX = (calcP[0].x - posx)*cos(radian) - (calcP[0].y - posy) * sin(radian) + posx;
		tempY = (calcP[0].x - posx) * sin(radian) + (calcP[0].y - posy) * cos(radian) + posy;

		calcP[i] = { tempX, tempY };
	}
}

void cStar::DrawFigureShape(HDC hdc)
{
	Polygon(hdc, starPos, 10);
}

void cStar::MovePos()
{
	BasicFigure::MovePos();
	POINT _movePos = GetMovePos();
	for (int i = 0; i < 10; i++)
	{
		this->starPos[i].x += _movePos.x;
		this->starPos[i].y += _movePos.y;
	}
}

void cStar::Update(RECT rectView)
{
	int rndpos = GetPosRnd();
	if (starPos[0].x - rndpos <= rectView.left || starPos[2].x - rndpos <= rectView.left || starPos[4].x - rndpos <= rectView.left || starPos[6].x + rndpos + (rndpos / 2) >= rectView.right || starPos[8].x + rndpos + (rndpos / 2) >= rectView.right)
		SetMovePosX(-1);

	if (starPos[0].y <= rectView.top || starPos[2].y <= rectView.top || starPos[4].y <= rectView.top || starPos[6].y >= rectView.bottom || starPos[8].y >= rectView.bottom)
		SetMovePosY(-1);
}