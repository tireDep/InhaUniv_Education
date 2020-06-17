// Q. ��(x, y)�� �Է¹޾� �� ���� (0, 0)�� �߽����� �ϰ� ������ r�� ���� ���ο� �����ϴ��� �˻��ϴ� ���α׷� �ۼ�
// ex)
// r = 10, x = 4, y =5
// �� (4, 5)�� ������ 10�� �� �ȿ� �ֽ��ϴ�
// r = 10, x = 9, y = 9
// �� (9, 9)�� ������ 10�� �� �ȿ� ���� �ʽ��ϴ�

// ���� ���ο� �����ϴ��� �˻��ϴ� �Լ��� �����, ��(x, y)�� ���ڷ� �Ѱ��� �� ����ü�� �̿��ؼ� ó��
// ������ ����ü

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
	int radius;	// ������
	int length;

	cout << "�������� �Է��ϼ��� : ";
	cin >> radius;

	cout << "���� ��ǥ�� �Է��ϼ���(x, y) : ";
	cin >> point.x >> point.y;

	CalcLength(&point, &length);
	PrintCircle(&point, length, radius);

	return 0;
}

void CalcLength(POINT_S *point, int *length)
{
	// �� �� ������ ���� : root{ (x2 - x1)^2 + (y2 - y1)^2 }  
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
		cout << "\n��(" << point->x << ", " << point->y << ")�� ������ " << radius << "�� �� �ȿ� �ֽ��ϴ�.\n";
	else
		cout << "\n��(" << point->x << ", " << point->y << ")�� ������ " << radius << "�� �� �ۿ� �ֽ��ϴ�.\n";
}
