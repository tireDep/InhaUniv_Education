// 183p
#include<stdio.h>

int main()
{
	int nAge = 0;

	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &nAge);

	if (nAge >= 20)
		printf("����� ���̴� %d�� �Դϴ�.\n", nAge);

	puts("End");

	return 0;
}