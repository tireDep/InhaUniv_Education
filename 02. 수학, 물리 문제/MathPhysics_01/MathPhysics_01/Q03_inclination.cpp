// Q. �� ���� ��(x1, y1)�� (x2, y2)�� ��ǥ�� �Է¹޾� �� ���� �մ� ���� ���⸦ ����ϴ� ���α׷��� �ۼ��϶�
// ���� : (y2 - y1) / (x2 - x1)

#include<iostream>

using namespace std;

int main()
{
	int x1, y1, x2, y2;
	int result = 0;

	cout << "ù��° ��ǥ �Է�(x1, y1) : ";
	cin >> x1 >> y1;
	cout << endl << "�ι�° ��ǥ �Է�(x2, y2) : ";
	cin >> x2 >> y2;

	result = (y2 - y1) / (x2 - x1);
	cout << endl << "���� �� : " << result << endl;

	return 0;
}