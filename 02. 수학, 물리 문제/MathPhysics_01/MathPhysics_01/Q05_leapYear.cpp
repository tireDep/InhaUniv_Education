// Q. ������ ����ϴ� ���α׷��� �ۼ��϶�
// 4�� ������ �������鼭 100���δ� ������ �������� �ʰų�, 400���� ������ �������� �ش� �����̴�.

#include<iostream>

using namespace std;

int main()
{
	int inputYear;

	cout << "�⵵ �Է� : ";
	cin >> inputYear;

	if (inputYear % 4 == 0 && inputYear % 100 != 0)
		cout << "�Է��� �⵵�� �����Դϴ�." << endl;
	else if (inputYear % 400 == 0)
		cout << "�Է��� �⵵�� �����Դϴ�." << endl;
	else
		cout << "�Է��� �⵵�� ����Դϴ�." << endl;

	return 0;
}