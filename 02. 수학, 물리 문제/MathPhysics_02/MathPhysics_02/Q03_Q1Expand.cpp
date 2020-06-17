// 오브젝트의 충돌 판별(2D 기본 충돌판정)

// Q. 두 개의 원에 대해 중심점 좌표 (x, y)와, 반지름 r을 입력받아
// 두 번째 원이 첫 번째 원의 내부에 있는지, 첫 번째 원과 겹치는 지를 판단하는 프로그램 작성
// 내부 / 외부 판단

// ex)
// C1 : 0.5, 5.1, 13
// C2 : 1, 1.7, 4.5
// => C2는 C1의 내부에 있다.

// [ 전제조건 : 처음 입력이 큼 ]

#include<iostream>
#include<cmath>

using namespace std;

struct CIRCLE_S
{
	float x;
	float y;
	float r;
};

void InputCircle(CIRCLE_S *firstCir, CIRCLE_S *secCir);
void CirPos(CIRCLE_S firstCir, CIRCLE_S secCir);

int main()
{
	CIRCLE_S firstCir;
	CIRCLE_S secCir;
	InputCircle(&firstCir, &secCir);
	CirPos(firstCir, secCir);

	return 0;
}

void InputCircle(CIRCLE_S *firstCir, CIRCLE_S *secCir)
{
	cout << "첫 번째 원 좌표 입력(중심점 좌표 : x, y) : ";
	cin >> firstCir->x >> firstCir->y;
	cout << "첫 번째 원 좌표 입력(반지름 : r) : ";
	cin >> firstCir->r;

	cout << "두 번째 원 좌표 입력(중심점 좌표 : x, y) : ";
	cin >> secCir->x >> secCir->y;
	cout << "두 번째 원 좌표 입력(반지름 : r) : ";
	cin >> secCir->r;
}

void CirPos(CIRCLE_S firstCir, CIRCLE_S secCir)
{
	int x = pow(firstCir.x - secCir.x, 2);
	int y = pow(firstCir.y - secCir.y, 2);
	int length = (x + y, 0.5);

	if (firstCir.r + secCir.r == length)
		cout << "한 점에서 만남" << endl;
	else if (firstCir.r - secCir.r >= 0)
		cout << "내부에 위치" << endl;
	else
		cout << "외부에 위치" << endl;
}