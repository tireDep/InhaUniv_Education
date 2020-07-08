// iomanip�� �����ڵ��� �����
// � �ý��ۿ����� ��Ŀ���� ���� ���̺귯���� ��������� �����ؾ� ��

#include<iostream>
#include<iomanip>
#include<cmath>

int main()
{
	using namespace std;
	// ���ο� ǥ�� �����ڸ� ���
	cout << fixed << right;

	// iomanip �����ڵ��� �����
	cout << setw(6) << "N" << setw(14) << "������" << setw(15) << "��������\n";

	double root;
	for (int n = 10; n <= 100; n += 10)
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('.') << n << setfill(' ')
			<< setw(12) << setprecision(3) << root
			<< setw(14) << setprecision(4) << sqrt(root)
			<< endl;
	}

	return 0;
}