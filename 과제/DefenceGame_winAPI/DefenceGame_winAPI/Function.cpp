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

void DrawHpBar(HDC hdc, int _loseHpPoint)
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

	SetColor(hdc, hPen, oldPen, 50, 50, 50);
	SetColor(hdc, hBrush, oldBrush, 50, 50, 50);

	MoveToEx(hdc, 0, 656, NULL);
	LineTo(hdc, 500, 656);

	Rectangle(hdc, 0, 656, 500 - _loseHpPoint, 700);

	DeleteColor(hdc, hPen, oldPen);
	DeleteColor(hdc, hBrush, oldBrush);
	
	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc,_loseHpPoint, 485);
	TextOut(hdc, 10, 665, _T("H"), _tcslen(_T("H")));

	SetTextColor(hdc, _loseHpPoint, 475);
	TextOut(hdc, 20, 665, _T("P"), _tcslen(_T("P")));
}

void SetTextColor(HDC hdc, int _loseHpPoint, int checkNum)
{
	if (_loseHpPoint < checkNum)
		SetTextColor(hdc, RGB(255, 255, 255));
	else
		SetTextColor(hdc, RGB(0, 0, 0));
}