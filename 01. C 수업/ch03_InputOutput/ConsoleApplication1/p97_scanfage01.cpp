// 97p
#include<stdio.h>

int main()
{
	char szName[32] = { 0 };
	int nAge = 0;

	printf("나이를 입력하세요 : ");
	scanf_s("%d", &nAge);

	printf("이름을 입력하세요 : ");
	gets_s(szName);

	printf("%d, %s\n", nAge, szName);

	return 0;
}