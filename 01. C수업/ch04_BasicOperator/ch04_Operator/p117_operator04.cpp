// 117p
#include<stdio.h>

int main()
{
	int x = 0;
	scanf_s("���� �Է� : %d", &x);

	printf("�� : %d\n", x / 3);
	printf("������ : %d\n", x % 3);

	return 0;
}
// ������ �����ڴ� �Ǽ� ����! => �Ǽ� ���·� �۾��� �Ǿ����

/*
float y = 0;
scanf_s("���� �Է� : %f", &y);
printf("�� : %f\n", y / 3.0);
printf("������ : %f\n", y % 3.0);

������� ����
*/