#include "stdafx.h"
#include "Class.h"

void BasicFigure::Update(BasicFigure figure[], RECT viewRect, int cnt)
{
	int _left;
	int _top;
	int _right;
	int _bottom;

	int addNum = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (figureShape == 5)	// 별 모양 벽판정
			addNum = -figure[i].rndPos;

		_left = figure[i].point.x + addNum;
		_top = figure[i].point.y + addNum;
		_right = figure[i].point.x + figure[i].rndPos;
		_bottom = figure[i].point.y + figure[i].rndPos;

		if (_left <= viewRect.left || _right >= viewRect.right)
		{
			figure[i].movePoint.x *= -1;
		}
		else if (_top <= viewRect.top || _bottom >= viewRect.bottom)
		{
			figure[i].movePoint.y *= -1;
		}
	}
}

void BasicFigure::SetPos(int x, int y, RECT viewRect)
{
	srand((unsigned)time(NULL));

	point.x = x;
	point.y = y;
	rndPos = rand() % 150 + 10;	// 랜덤 크기 설정

	int addNum = 0;
	if (figureShape == 5)	// 별 모양 벽판정
		addNum = -rndPos;

	while (viewRect.right <= point.x + rndPos || viewRect.bottom <= point.y + rndPos || viewRect.left >= point.x + addNum || viewRect.top >= point.y + addNum)	// 범위 벗어날 경우 크기 재설정
	{
		rndPos = rand() % 100 + 1;
		addNum = -rndPos;
	}

	CalcRadius();
}

void BasicFigure::CalcRadius()
{
	double calcX = pow(point.x - point.y, 2);
	double calcY = pow((point.x + rndPos) - (point.y + rndPos), 2);

	radius = pow(calcX + calcY, 0.5) / 2;
}

void BasicFigure::MovePos(BasicFigure figure[], int cnt)
{
	srand((unsigned)time(NULL));
	int direction;

	for (int i = 0; i < cnt; i++)
	{
		if (movePoint.x == 0)
		{
			direction = rand() % 2;
			movePoint.x = rand() % 10 + 1;
			if (direction % 2 == 0)
				movePoint.x *= -1;

			direction = rand() % 2;
			movePoint.y = rand() % 10 + 1;
			if (direction % 2 == 0)
				movePoint.y *= -1;
		}

		figure[i].point.x += figure[i].movePoint.x;
		figure[i].point.y += figure[i].movePoint.y;
	}
}

void BasicFigure::Collision(BasicFigure circle[], BasicFigure rectangle[])
{

}

/*
double DegreeToRadian(int arcDegree)
{
return arcDegree * M_PI / 180;
}

void DrawSunflower(HDC hdc, int centerX, int centerY, int centerR, int num)
{
DrawCircle(hdc, centerX, centerY, centerR);

int arcDegree = 360 / num;
double rad = DegreeToRadian(arcDegree);
int arc2 = arcDegree / 2;
double rad2 = DegreeToRadian(arc2);
int sonR = centerR * sin(rad2) / (1 - sin(rad2));

double sonX = centerX;
double sonY = centerY + centerR + sonR;
for (int i = 0; i < num; i++)
{
DrawCircle(hdc, sonX, sonY, sonR);
double tempX = cos(rad) * (sonX - centerX) - sin(rad) * (sonY - centerY);
double tempY = sin(rad) * (sonX - centerX) + cos(rad) * (sonY - centerY);
// 삼각함수 회전변환
sonX = tempX + centerX;
sonY = tempY + centerY;
}
}

void AddPoint(int degree, int midX, int midY, POINT point[])
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
*/

double BasicFigure::CalcRadian(double degree)
{
	return degree * M_PI / 180;
}

void BasicFigure::Rotation(double degree) 
{
	int addDeg = degree;
	double radian;
	CalcRadian(degree);
	POINT rotatePos[4] = { point.x, point.y, point.x + rndPos, point.y + rndPos };
	// left, top, right, bottom


}

int BasicFigure::GetPosX()
{
	return point.x;
}

int BasicFigure::GetPosY()
{
	return point.y;
}

int BasicFigure::GetPosRnd()
{
	return rndPos;
}