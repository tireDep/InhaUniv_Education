// Q. �� ��(x1, y1) (x2, y2)�� �Է¹޾� �� �� �� ������ �Ÿ��� ����ϴ� ���α׷� �ۼ�
// �Ÿ���� ������
// squar root { (x2 - x1)^2 + (y2 - y1)^2 }
// squar root a�� ����ϱ� ���� pow(a, 0.5)�� ����� �� ���� | sqrt()�Լ��� ����� �� �� ����
// ex)
// x1, y1 : 1.5, -3.4
// x2, y2 : 4, 5
// Distance : 8.764...

// �� �� ������ �Ÿ� ���
// squar root { (x2 - x1)^2 + (y2 - y1)^2 }

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double x1, x2, y1, y2;
	double result = 0;
	cout << "Input x1, y1 : ";
	cin >> x1 >> y1;
	cout << endl << "Input x2, y2 : ";
	cin >> x2 >> y2;

	result = pow((x2 - x1), 2) + pow((y2 - y1), 2);
	result = pow(result, 0.5);
	cout << endl << "Distance : " << result << endl;

	return 0;
}