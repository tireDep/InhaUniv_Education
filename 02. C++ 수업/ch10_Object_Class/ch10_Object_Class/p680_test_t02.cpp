// Q. x�� y���� ���� ǥ���ϴ� MyPoint Ŭ������ �����϶�
// 1) ��ǥ�� ��Ÿ���� �� ���� x, y ������ �ʵ�
// 2) ��(0, 0)�� �����ϴ� �μ� ���� ������
// 3) ���� ��ǥ�� ���� �����ϴ� ������
// 4) x�� y�� ������ �ʵ带 ���� ���� �ΰ��� get �Լ�
// 5) MyPoint ������ �� ������ �ٸ� �������� �Ÿ��� ��ȯ�ϴ� distance �Լ�
// Ŭ������ ���� UML ���̾�׷��� �׸���, Ŭ������ �����϶�
// �� ���� ��(0, 0)�� ��(10, 30.5)�� �����ϰ� �� �� ������ �Ÿ��� ǥ���ϴ� �׽�Ʈ ���α׷��� �ۼ��϶�.

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

	cout << "������ ù ��° ���� ��ǥ\nx : " << fSpot.GetPosX() << ", y : " << fSpot.GetPosY() << endl;
	cout << "������ �� ��° ���� ��ǥ\nx : " << sSpot.GetPosX() << ", y : " << sSpot.GetPosY() << endl;
	cout << "�� �� ������ �Ÿ�\n" << fSpot.GetDistance(sSpot) << endl;	// Ŭ���� ��ü ���ٴ� ���۷����� �Ѱ� �ִ� ���� ����
	return 0;
}