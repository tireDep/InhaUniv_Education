// Q. x와 y축의 점을 표시하는 MyPoint 클래스를 설계하라
// 1) 좌표를 나타내는 두 개의 x, y 데이터 필드
// 2) 점(0, 0)을 생성하는 인수 없는 생성자
// 3) 지정 좌표의 점을 생성하는 생성자
// 4) x와 y의 데이터 필드를 위한 각각 두개의 get 함수
// 5) MyPoint 유형이 한 점에서 다른 점까지의 거리를 반환하는 distance 함수
// 클래스에 대한 UML 다이어그램을 그리고, 클래스를 구현하라
// 두 개의 점(0, 0)과 점(10, 30.5)를 생성하고 두 점 사이의 거리를 표시하는 테스트 프로그램을 작성하라.

#include<iostream>
#include<cmath>

class MYPOINT_C
{
private:
	double x;
	double y;

public:
	MYPOINT_C();
	MYPOINT_C(double pX, double pY);
	~MYPOINT_C();

	double GetPosX();
	double GetPosY();
	double GetDistance(MYPOINT_C point);
};

// MYPOINT_C::MYPOINT_C()
// {
// 	x = 0;
// 	y = 0;
// }

MYPOINT_C::MYPOINT_C() : x(0), y(0)
{

}

// MYPOINT_C::MYPOINT_C(double pX, double pY)
// {
// 	x = pX;
// 	y = pY;
// }

MYPOINT_C::MYPOINT_C(double pX, double pY) : x(pX), y(pY)
{

}

MYPOINT_C::~MYPOINT_C()
{

}

double MYPOINT_C::GetPosX()
{
	return this->x;
}

double MYPOINT_C::GetPosY()
{
	return this->y;
}

double MYPOINT_C::GetDistance(MYPOINT_C point)
{
	double xLenght = pow(this->x - point.x, 2);
	double yLenght = pow(this->y - point.y, 2);

	return pow(xLenght + yLenght, 0.5);
}

int main()
{
	using std::cout;
	using std::endl;
	MYPOINT_C fSpot;
	MYPOINT_C sSpot(10, 30.5);

	cout << "생성된 첫 번째 점의 좌표\nx : " << fSpot.GetPosX() << ", y : " << fSpot.GetPosY() << endl;
	cout << "생성된 두 번째 점의 좌표\nx : " << sSpot.GetPosX() << ", y : " << sSpot.GetPosY() << endl;
	cout << "두 점 사이의 거리\n" << fSpot.GetDistance(sSpot) << endl;	// 클래스 전체 보다는 레퍼런스만 넘겨 주는 것이 좋음
	return 0;
}