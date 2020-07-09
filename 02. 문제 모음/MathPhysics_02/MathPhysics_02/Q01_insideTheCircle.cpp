// Q. 점(x, y)를 입력받아 그 점이 (0, 0)을 중심으로 하고 반지름 r인 원의 내부에 존재하는지 검사하는 프로그램 작성
// ex)
// r = 10, x = 4, y =5
// 점 (4, 5)는 반지름 10인 원 안에 있습니다
// r = 10, x = 9, y = 9
// 점 (9, 9)는 반지름 10인 원 안에 있지 않습니다

// 점이 내부에 존재하는지 검사하는 함수를 만들고, 점(x, y)를 인자로 넘겨줄 때 구조체를 이용해서 처리
// 포인터 구조체

#include<iostream>
#include<cmath>

using namespace std;

struct POINT_S
{
	int x;
	int y;
};

void CalcLength(POINT_S *point, int *length);
void PrintCircle(POINT_S *point, int length, int radius);

int main()
{
	POINT_S point;
	int radius;	// 반지름
	int length;

	cout << "반지름을 입력하세요 : ";
	cin >> radius;

	cout << "점의 좌표를 입력하세요(x, y) : ";
	cin >> point.x >> point.y;

	CalcLength(&point, &length);
	PrintCircle(&point, length, radius);

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
