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

class RECTANGLE_C
{
public:
	RECTANGLE_C();
	~RECTANGLE_C();

	void SetWidth();
	void SetHeight();
	double GetWidth();
	double GetHeight();

	double GetArea();
	double GetPerimeter();

private:
	double width;
	double height;
};

RECTANGLE_C::RECTANGLE_C()
{
	width = 1;
	height = 1;
}

RECTANGLE_C::~RECTANGLE_C()
{

}

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
	return this->width * this->height;
}

double RECTANGLE_C::GetPerimeter()
{
	return (this->width + this->height) * 2;
}

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	RECTANGLE_C rectangle1;
	RECTANGLE_C rectangle2;

	cout << "ù ��° ���簢��" << endl;
	rectangle1.SetWidth();
	rectangle1.SetHeight();
	cout << "���� : " << rectangle1.GetWidth() << ", ���� : " << rectangle1.GetHeight() 
		<< ", ���� : " << rectangle1.GetArea() << ", �ѷ� ���� : " << rectangle1.GetPerimeter() << endl;

	cout << endl << "�� ��° ���簢��" << endl;
	rectangle2.SetWidth();
	rectangle2.SetHeight();
	cout << "���� : " << rectangle2.GetWidth() << ", ���� : " << rectangle2.GetHeight() 
		<< ", ���� : " << rectangle2.GetArea() << ", �ѷ� ���� : " << rectangle2.GetPerimeter() << endl;

	return 0;
}