// ������Ʈ�� �浹 �Ǻ�(2D �⺻ �浹����)

// Q. �� ���� ���� ���� �߽��� ��ǥ (x, y)��, ������ r�� �Է¹޾�
// �� ��° ���� ù ��° ���� ���ο� �ִ���, ù ��° ���� ��ġ�� ���� �Ǵ��ϴ� ���α׷� �ۼ�
// ���� / �ܺ� �Ǵ�

// ex)
// C1 : 0.5, 5.1, 13
// C2 : 1, 1.7, 4.5
// => C2�� C1�� ���ο� �ִ�.

// [ �������� : ó�� �Է��� ŭ ]

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
	cout << "ù ��° �� ��ǥ �Է�(�߽��� ��ǥ : x, y) : ";
	cin >> firstCir->x >> firstCir->y;
	cout << "ù ��° �� ��ǥ �Է�(������ : r) : ";
	cin >> firstCir->r;

	cout << "�� ��° �� ��ǥ �Է�(�߽��� ��ǥ : x, y) : ";
	cin >> secCir->x >> secCir->y;
	cout << "�� ��° �� ��ǥ �Է�(������ : r) : ";
	cin >> secCir->r;
}

void CirPos(CIRCLE_S firstCir, CIRCLE_S secCir)
{
	int x = pow(firstCir.x - secCir.x, 2);
	int y = pow(firstCir.y - secCir.y, 2);
	int length = (x + y, 0.5);

	if (firstCir.r + secCir.r == length)
		cout << "�� ������ ����" << endl;
	else if (firstCir.r - secCir.r >= 0)
		cout << "���ο� ��ġ" << endl;
	else
		cout << "�ܺο� ��ġ" << endl;
}