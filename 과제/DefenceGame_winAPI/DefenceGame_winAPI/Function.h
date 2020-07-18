#pragma once

double DegreeToRadian(int degree);

POINT PointRotate(int centerX, int centerY, int degree, const POINT * point);

POINT PointRotate(int centerX, int centerY, double rad, const POINT * point);

void SetColor(HDC hdc, HPEN &hPen, HPEN &oldPen, int r, int g, int b);
void SetColor(HDC hdc, HBRUSH &hBrush, HBRUSH &oldBrush, int r, int g, int b);

void DeleteColor(HDC hdc, HPEN &hPen, HPEN &oldPen);
void DeleteColor(HDC hdc, HBRUSH &hBrush, HBRUSH &oldBrush);

void DrawHpBar(HDC hdc, int _hpPoint);
