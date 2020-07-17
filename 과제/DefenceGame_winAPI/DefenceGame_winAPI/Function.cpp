#include"stdafx.h"
#include"Function.h"

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
	Arc(hdc, 200, 600, 300, 670, 350, 670, 150, 670);

	HPEN hPen, oldPen;
	hPen = CreatePen(PS_SOLID, 1, RGB(50, 50, 50));
	oldPen = (HPEN)SelectObject(hdc, hPen);

	HBRUSH hBrush, oldBrush;
	hBrush = CreateSolidBrush(RGB(50, 50, 50));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	// oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

	
	Rectangle(hdc, 205, 650, 295, 750);
	
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}