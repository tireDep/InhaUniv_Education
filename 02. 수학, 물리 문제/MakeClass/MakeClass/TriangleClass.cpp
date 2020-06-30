#include<iostream>
#include<string>
#include<cmath>
#include "GemometricObject.h"

using std::string;

TRIANGLE_S::TRIANGLE_S() : side1(1.0), side2(1.0), side3(1.0), isFilled(false) { }

TRIANGLE_S::TRIANGLE_S(double s1, double s2, double s3) 
: side1(s1), side2(s2), side3(s3), isFilled(false) { }

TRIANGLE_S::~TRIANGLE_S() { }

double TRIANGLE_S::GetSide1() const
{
	return side1;
}

double TRIANGLE_S::GetSide2() const
{
	return side2;
}

double TRIANGLE_S::GetSide3() const
{
	return side3;
}

double TRIANGLE_S::GetArea()
{
	// 헤론의 공식
	double s = 0;
	s = (side1 + side2 + side3) / 2;
	area = pow(s * (s - side1) * (s - side2) * (s - side3), 0.5);
	return area;
}

double TRIANGLE_S::GetPerimeter()
{
	length = side1 + side2 + side3;
	return length;
}

void TRIANGLE_S::SetColor()
{
	std::cout << "색상입력 : ";
	std::cin >> color;
}

string TRIANGLE_S::GetColor()
{
	return color;
}

bool TRIANGLE_S::CheckFilled()
{
	int inputNum;
	std::cout << "색상 칠함 여부 입력 (0(X), 1(O)) : ";
	std::cin >> inputNum;

	if (inputNum == 0)
		isFilled = false;
	else
		isFilled = true;

	return isFilled;
}