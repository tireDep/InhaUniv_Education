// 66p
#include<stdio.h>

int main()
{
	char szName[32] = { 0 };

	printf("�̸��� �Է��ϼ��� : ");
	gets_s(szName);

	int nSize = sizeof(szName);
	printf("szName size : %d\n", nSize);

	printf("����� �̸��� ");
	puts(szName);
	puts("�Դϴ�.\n");

	return 0;
}