// Q. ���簢���� ��Ÿ���� Rectangle �̶� �̸��� Ŭ������ �����϶�. Ŭ������ ������ �����Ѵ�.
// 1) ���簢���� ���� ���̸� ��Ÿ���� width, height��� �̸��� double �ʵ�
// 2) width�� height�� ���� 1�� ���簢���� �����ϴ� �μ� ���� ������
// 3) ������ width�� height�� ���� �⺻ ���簢���� �����ϴ� ������
// 4) ��� ������ �ʵ忡 ���� �����ڿ� ������ �Լ� : setWidth(), setHeight(), getWidth(), getHeight()
// 5) ���簢���� ���� ���� ��ȯ�ϴ� getArea() �Լ�
// 6) �ѷ� ���̸� ��ȯ�ϴ� getPerimeter() �Լ�

// �� ���� Rectangle ��ü�� �����ϴ� �׽�Ʈ ���α׷��� �ۼ��ϰ�,
// ù ��° ��ü : width = 4, height = 40
// �� ��° ��ü : width = 3.5, height = 35.9
// �� ���� �Ҵ��ϰ�, �� ��ü�� �Ӽ��� ǥ���ϰ� ������ �ѷ� ���� ����϶�.

// ex) w = 4, h = 40, area = 160, per = 88

#include<iostream>
#include"GemometricObject.h"

RECTANGLE_C::RECTANGLE_C() : width(1), height(1) { }

RECTANGLE_C::RECTANGLE_C(double w, double h) : width(w), height(h) { }

RECTANGLE_C::~RECTANGLE_C() { }

void RECTANGLE_C::SetWidth()
{
	std::cout << "���簢���� ���� : ";
	std::cin >> this->width;
}

void RECTANGLE_C::SetHeight()
{
	std::cout << "���簢���� ���� : ";
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
