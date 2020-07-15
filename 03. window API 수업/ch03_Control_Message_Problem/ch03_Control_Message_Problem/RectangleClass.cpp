#include "stdafx.h"
#include "Class.h"

void cRect::DrawFigure(HDC hdc)
{
	int _x = GetPosX();
	int _y = GetPosY();
	int _rnd = GetPosRnd();

	Rectangle(hdc, _x, _y + 50, _x + _rnd, _y + _rnd);
}

void cRect::Rotation(double degree)
{
	// int _cX = GetCenterX();
	// int _cY = GetCenterY();
	// int _x = GetPosX();
	// int _y = GetPosY();
	// int _rnd = GetPosRnd();
	// POINT rotatePos[2] = { _x, _y };
	// // left, top, right, bottom
	// 
	// double radian;
	// int addDeg = degree;
	// int spotX;
	// int spotY;
	// 
	// radian = degree * (M_PI / 180);
	// 
	// spotX = (_x) * cos(radian) - (_y) * sin(radian);
	// spotY = (_x + _rnd) * sin(radian) + (_y + _rnd) * cos(radian);
	// 
	// SetPosX(spotX);
	// SetPosY(spotY);
	

	/*
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
	*/

	// int arcDegree = 360 / num;
	// double rad = DegreeToRadian(arcDegree);
	// int arc2 = arcDegree / 2;
	// double rad2 = DegreeToRadian(arc2);
	// int sonR = centerR * sin(rad2) / (1 - sin(rad2));
	// 
	// double sonX = centerX;
	// double sonY = centerY + centerR + sonR;
	// for (int i = 0; i < num; i++)
	// {
	// 	double tempX = cos(rad) * (sonX - centerX) - sin(rad) * (sonY - centerY);
	// 	double tempY = sin(rad) * (sonX - centerX) + cos(rad) * (sonY - centerY);
	// 	// 삼각함수 회전변환
	// 	sonX = tempX + centerX;
	// 	sonY = tempY + centerY;
	// }
}