// Q2. 점(x, y)를 입력받아 그 점이 (0, 0)을 중심으로 하고 폭 w, 높이 h인 직사각형의 내부에 존재하는 지를 검사하는 프로그램을 작성
// ex)
// w = 10, h = 5, x = 2, y =2
// 점(2, 2)는 사각형 내부에 존재
// w = 10, h = 5, x = 6, y =4
// 점(6, 4)는 사각형 외부에 존재

// 점 입력은 구조체를 이용해서 처리, 포인터로 넘겨줄 것

#include<iostream>
#include<cmath>

using namespace std;

struct POINT_S
{
	int x;
	int y;
};

struct RECTANGLE_S
{
	float w;
	float h;
};

void CalcLength(POINT_S *point, int *length);
void PrintCircle(POINT_S *point, int length, int radius);
void PrintRectangle(RECTANGLE_S *rectangle, POINT_S *point, int length);

int main()
{
	RECTANGLE_S rectangle;
	POINT_S point;
	int length;

	cout << "직사각형의 가로, 세로를 입력하세요 : ";
	cin >> rectangle.w >> rectangle.h;

	cout << "점의 좌표를 입력하세요(x, y) : ";
	cin >> point.x >> point.y;
	CalcLength(&point, &length);
	PrintRectangle(&rectangle, &point, length);


	return 0;
}

void CalcLength(POINT_S *point, int *length)
{
	// 두 점 사이의 길이 : root{ (x2 - x1)^2 + (y2 - y1)^2 }  
	//	x1 = y1 = 0
	// root{x2^2 + y2^2} => length

	int x, y;
	x = pow(point->x, 2);
	y = pow(point->y, 2);
	*length = pow(x + y, 0.5);
}

void PrintCircle(POINT_S *point, int length, int radius)
{
	if (length <= radius)
		cout << "\n점(" << point->x << ", " << point->y << ")는 반지름 " << radius << "인 원 안에 있습니다.\n";
	else
		cout << "\n점(" << point->x << ", " << point->y << ")는 반지름 " << radius << "인 원 밖에 있습니다.\n";
}

void PrintRectangle(RECTANGLE_S *rectangle, POINT_S *point, int length)
{
	float halfW = rectangle->w / 2;
	float halfH = rectangle->h / 2;
	bool isCheck = false;

	if (point->y <= halfH)
		isCheck = true;
	if (point->x <= halfW)
		isCheck = true;

	if (isCheck)
		cout << "\n점(" << point->x << ", " << point->y << ")는 사각형 내부에 존재 합니다.\n";
	else
		cout << "\n점(" << point->x << ", " << point->y << ")는 사각형 외부에 존재 합니다.\n";
}