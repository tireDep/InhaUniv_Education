// p170

#include<stdio.h>

int Gcd(int x, int y);

int main()
{
	int x, y;
	puts("�� ������ �ִ� ������� ���մϴ�.");
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &x);
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &y);
	printf("�ִ������� %d�Դϴ�.\n", Gcd(x, y));

	return 0;
}

int Gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return Gcd(y, x%y);
}