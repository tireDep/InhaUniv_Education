#pragma once

double DegreeToRadian(int degree);

POINT PointRotate(int centerX, int centerY, int degree, const POINT * point);

POINT PointRotate(int centerX, int centerY, double rad, const POINT * point);

void DrawHpBar(HDC hdc, int _hpPoint);
