// 97p
#include<stdio.h>

int main()
{
	char szName[32] = { 0 };
	int nAge = 0;

	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &nAge);

	printf("�̸��� �Է��ϼ��� : ");
	gets_s(szName);

	printf("%d, %s\n", nAge, szName);

	return 0;
}