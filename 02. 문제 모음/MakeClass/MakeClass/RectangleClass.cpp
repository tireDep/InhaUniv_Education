// Q. 직사각형을 나타내는 Rectangle 이란 이름의 클래스를 설계하라. 클래스는 다음을 포함한다.
// 1) 직사각형의 폭과 높이를 나타내는 width, height라는 이름의 double 필드
// 2) width와 height의 값이 1인 직사각형을 생성하는 인수 없는 생성자
// 3) 지정된 width와 height를 갖는 기본 직사각형을 생성하는 생성자
// 4) 모든 데이터 필드에 대한 접근자와 변경자 함수 : setWidth(), setHeight(), getWidth(), getHeight()
// 5) 직사각형의 면적 값을 반환하는 getArea() 함수
// 6) 둘레 길이를 반환하는 getPerimeter() 함수

// 두 개의 Rectangle 객체를 생성하는 테스트 프로그램을 작성하고,
// 첫 번째 객체 : width = 4, height = 40
// 두 번째 객체 : width = 3.5, height = 35.9
// 를 각각 할당하고, 두 객체의 속성을 표시하고 면적과 둘레 길이 계산하라.

// ex) w = 4, h = 40, area = 160, per = 88

#include<iostream>
#include"GemometricObject.h"

RECTANGLE_C::RECTANGLE_C() : width(1), height(1) { }

RECTANGLE_C::RECTANGLE_C(double w, double h) : width(w), height(h) { }

RECTANGLE_C::~RECTANGLE_C() { }

void RECTANGLE_C::SetWidth()
{
	std::cout << "직사각형의 가로 : ";
	std::cin >> this->width;
}

void RECTANGLE_C::SetHeight()
{
	std::cout << "직사각형의 세로 : ";
	std::cin >> this->height;
}

double RECTANGLE_C::GetWidth()
{
	return this->width;
}

double RECTANGLE_C::GetHeight()
{
	return this->height;
}

double RECTANGLE_C::GetArea()
{
	area = this->width * this->height;
	return area;
}

double RECTANGLE_C::GetPerimeter()
{
	length = (this->width + this->height) * 2;
	return length;
}
