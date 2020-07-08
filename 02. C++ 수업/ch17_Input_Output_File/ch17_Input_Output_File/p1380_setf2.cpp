// setf()�� 2���� �Ű������� ����Ͽ� ��� ������ ����
#include<iostream>
#include<cmath>

int main()
{
	using namespace std;
	// ���� ���� ���, �÷��� ��ȣ ���
	// ���е� 3, �ڿ� �ٴ� 0���� ���
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);
	
	// ������ E ǥ�� ���, ������ ��� ���� ������ ����
	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);

	cout << "���� ����\n";
	long n;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	// ����(internal) ���ķ� ����
	cout.setf(ios_base::internal, ios_base::adjustfield);
	// ����Ʈ �ε� �Ҽ��� ǥ��� ����
	cout.setf(old, ios_base::floatfield);
	cout << "����(internal) ����\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	// ������ ���� ���, ���� �Ҽ��� ǥ��� ���
	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "������ ����\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	return 0;
}