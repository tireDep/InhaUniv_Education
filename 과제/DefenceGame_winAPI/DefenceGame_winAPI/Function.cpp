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

void SetColor(HDC hdc, HPEN &hPen, HPEN &oldPen, int r, int g, int b)
{
	hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b));
	oldPen = (HPEN)SelectObject(hdc, hPen);
}

void DeleteColor(HDC hdc, HPEN &hPen, HPEN &oldPen)
{
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

void SetColor(HDC hdc, HBRUSH &hBrush, HBRUSH &oldBrush, int r, int g, int b)
{
	hBrush = CreateSolidBrush(RGB(r, g, b));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
}

void DeleteColor(HDC hdc, HBRUSH &hBrush, HBRUSH &oldBrush)
{
	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}

void DrawHpBar(HDC hdc, int _hpPoint)
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

	hPen = CreatePen(PS_SOLID, 1, RGB(200, 0, 0));
	oldPen = (HPEN)SelectObject(hdc, hPen);

	hBrush = CreateSolidBrush(RGB(200, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, 0, 656, 500 - _hpPoint, 700);

	SelectObject(hdc, oldPen);
	SelectObject(hdc, oldBrush);

	DeleteObject(hPen);
	DeleteObject(hBrush);
}
