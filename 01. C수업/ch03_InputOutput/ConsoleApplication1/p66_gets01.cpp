// 66p
#include<stdio.h>

int main()
{
	char szName[32] = { 0 };

	printf("이름을 입력하세요 : ");
	gets_s(szName);

	int nSize = sizeof(szName);
	printf("szName size : %d\n", nSize);

	printf("당신의 이름은 ");
	puts(szName);
	puts("입니다.\n");

	return 0;
}