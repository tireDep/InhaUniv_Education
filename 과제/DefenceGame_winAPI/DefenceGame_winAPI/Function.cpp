#include"stdafx.h"
#include"DefenceGame_winAPI.h"
#include"Function.h"

double DegreeToRadian(int degree)
{
	return degree * M_PI / 180;
}

POINT PointRotate(int centerX, int centerY, int degree, const POINT *point)
{
	double rad = DegreeToRadian(degree);

	double tempX = cos(rad) * (point->x - centerX) - sin(rad) * (point->y - centerY);
	double tempY = sin(rad) * (point->x - centerX) + cos(rad) * (point->y - centerY);
	POINT temp = { centerX + tempX, centerY + tempY };
	return temp;
}

POINT PointRotate(int centerX, int centerY, double rad, const POINT *point)
{
	double tempX = cos(rad) * (point->x - centerX) - sin(rad) * (point->y - centerY);
	double tempY = sin(rad) * (point->x - centerX) + cos(rad) * (point->y - centerY);
	POINT temp = { centerX + tempX, centerY + tempY };
	return temp;
}

void DrawHpBar(HDC hdc, int _hpPoint)
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

	hPen = CreatePen(PS_SOLID, 1, RGB(200, 0, 0));
	oldPen = (HPEN)SelectObject(hdc, hPen);

	hBrush = CreateSolidBrush(RGB(200, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, 0, 650, 500 - _hpPoint, 700);

	SelectObject(hdc, oldPen);
	SelectObject(hdc, oldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);
}

void DrawGun(HDC hdc)
{

	HPEN hPen, oldPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(50, 50, 50));
	oldPen = (HPEN)SelectObject(hdc, hPen);

	HBRUSH hBrush, oldBrush;
	hBrush = CreateSolidBrush(RGB(50, 50, 50));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	// oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

	
	//Rectangle(hdc, 205, 650, 295, 750);
	
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);

	//Rectangle(hdc, 245, 580, 255, 650);
	// POINT test[4] = { {245,580},{255,580},{255,650},{245,650} };
	// //Polygon(hdc, test, 4);
	// 
	// POINT center = { 250, 650 };
	// 
	// for (int i = 0; i < 4; i++)
	// {
	// 	test[i] = PointRotate(center.x, center.y, 15, &test[i]);
	// }
	//Polygon(hdc, test, 4);
	Arc(hdc, 200, 600, 300, 670, 350, 670, 150, 670);
	//Arc()
}

