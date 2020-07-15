#include "stdafx.h"
#include "Class.h"

void cStar::DrawFigure(HDC hdc)
{
	int _x = GetPosX();
	int _y = GetPosY();
	int _rnd = GetPosRnd();

	POINT point1[5] = { 0 };
	point1[0] = { _x, _y - _rnd };

	int degree = 72;
	AddPoint(degree, _x, _y, point1);

	// Å©·¡¸Ó
	double a, b, c, d, e, f;
	int posX, posY;

	a = point1[0].y - point1[2].y;
	b = -(point1[0].x - point1[2].x);
	e = a*point1[0].x + b*point1[0].y;

	c = point1[1].y - point1[4].y;
	d = -(point1[1].x - point1[4].x);
	f = c*point1[1].x + d*point1[1].y;

	double divide = (a*d) - (b*c);
	posX = ((e*d) - (b*f)) / divide;
	posY = ((a*f) - (e*c)) / divide;

	POINT point2[5] = { 0 };
	point2[0] = { posX, posY };
	AddPoint(degree, _x, _y, point2);

	POINT result[10] = { point1[0], point2[0],point1[1],point2[1],point1[2],point2[2],point1[3],point2[3],point1[4],point2[4] };
	Polygon(hdc, result, 10);
}

void cStar::AddPoint(int degree, int midX, int midY, POINT point[])
{
	int addDeg = degree;
	double radian;
	int spotX;
	int spotY;
	for (int i = 1; i < 5; i++)
	{
		radian = degree * (M_PI / 180);
		degree += addDeg;

		spotX = (point[0].x - midX) * cos(radian) - (point[0].y - midY) * sin(radian) + midX;
		spotY = (point[0].x - midX) * sin(radian) + (point[0].y - midY) * cos(radian) + midY;

		point[i] = { spotX, spotY };
	}
}
