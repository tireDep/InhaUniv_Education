// Q. GemometricObject Ŭ������ Ȯ���ϴ� Triangle Ŭ������ �����϶�
// �� Ŭ������ ������ �����Ѵ�.
// 1. �ﰢ���� �� ���� �����ϴ� 3���� double�� ������ �ʵ� side1, side2, side3
// 2. �� ���� 1.0�� �⺻ �ﰢ���� �����ϴ� �μ� ���� ������
// 3. ������ side1, side2, sdie3�� ���� �ﰢ���� �����ϴ� ������
// 4. ��� 3���� ������ �ʵ忡 ���� ��� ������ �Լ� (const access function)
// 5. �ﰢ���� ������ ��ȯ�ϴ� getArea() ��� �Լ�
// 6. �ﰢ���� �ѷ��� ��ȯ�ϴ� getPerimeter() ��� �Լ�

// Triangle Ŭ������ GeometricObject Ŭ������ �����ϴ� UML ���̾�׷��� �ۼ��ϰ� Ŭ������ ����,
// �ﰢ���� �� ��, ����� �ﰢ���� ä���������� ��Ÿ���� 1 �Ǵ� 0�� ����ڰ� �Է��ϴ� �׽�Ʈ ���α׷��� �ۼ�

// ���α׷��� �Է� ���� ����Ͽ� �ﰢ���� �� ��, ���� ���� �� ä�� ����(filled)
// �Ӽ��� ������ Triangle ��ü�� �����ؾ��ϸ�
// ����, �ѷ�, ���� �׸��� ä���������� ���θ� true �Ǵ� false�� ȭ�鿡 ����ؾ� �Ѵ�.

// +) Rectangle Ŭ������ ��ӹ޴� �������� �籸�� �� ��

#include"GemometricObject.h"
#include<iostream>

using namespace std;

int main()
{
	TRIANGLE_S triangle;	// 4, 5, 6 ���� 9.92157
	cout << "[�ﰢ��]" << endl;
	cout << "�ﰢ���� �� ���� ���� : " << triangle.GetSide1()
		<< ", " << triangle.GetSide2() << ", " << triangle.GetSide3() << endl;
	cout << "�ﰢ���� ���� : " << triangle.GetArea() << endl;
	cout << "�ﰢ���� �ѷ� : " << triangle.GetPerimeter() << endl;
	cout << "\n�ﰢ���� ���� & ä���� ����\n";
	triangle.SetColor();
	if (triangle.CheckFilled())
		cout << "TRUE\n=> �ﰢ���� " << triangle.GetColor() << " �������� ä����\n";
	else
		cout << "FALSE\n=> �ﰢ���� " << triangle.GetColor() <<" �������� ä������ ����\n";

	RECTANGLE_C rectangle;
	cout << endl << "[���簢��]" << endl;
	cout << "���簢���� �� ���� ���� : " << rectangle.GetWidth() << ", " << rectangle.GetHeight() << endl;
	cout << "���簢���� ���� : " << rectangle.GetArea() << endl;
	cout << "���簢���� �ѷ� : " << rectangle.GetPerimeter() << endl;
	
	CIRCLE_C circle;
	cout << endl << "[��]" << endl;
	cout << "���� ������ : " << circle.GetRadius() << endl;
	cout << "���� ���� : " << circle.GetArea() << endl;
	cout << "���� �ѷ� : " << circle.GetPerimeter() << endl;

	return 0;
}