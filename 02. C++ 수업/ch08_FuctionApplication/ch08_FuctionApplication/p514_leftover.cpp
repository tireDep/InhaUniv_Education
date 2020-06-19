// 514p

#include<iostream>

unsigned long left(unsigned long num, unsigned ct);
char *left(const char *str, int n = 1);

using namespace std;

int main()
{
	char *trip = "Hawaii!!";
	unsigned long n = 12345678;
	char *temp;

	for (int i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;	// ������ ���� �ӽ� ��� ������ �����Ѵ�
	}

	return 0;
}

// ���� num�� �տ������� ct ���� ���� ����
unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0)
		return 0;	// ���ڰ� ������ 0 ����
	while (n /= 10)
		digits++;

	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;	// �����ִ� ct���� ���� ����
		return num;
	}
	else
		return num;	// ct >= ��ü ���� ���� �̸� ���� ��ü ����
}

// str ���ڿ��� �տ������� n���� ���ڸ� ���Ͽ� ���ο� ���ڿ��� �����ϰ�, �̸� �����ϴ� ������ ����
char *left(const char *str, int n)
{
	if (n < 0)
		n = 0;

	char *p = new char[n + 1];
	int i;
	for (i = 0; i < n&&str[i]; i++)
		p[i] = str[i];	// ���ڿ� ����

	while (i <= n)
		p[i++] = '\0';	// ���ڿ� �������� '\0'���� ����

	return p;
}
