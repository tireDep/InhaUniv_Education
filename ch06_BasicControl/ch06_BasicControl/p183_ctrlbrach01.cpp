// 183p
#include<stdio.h>

int main()
{
	int nAge = 0;

	printf("나이를 입력하세요 : ");
	scanf_s("%d", &nAge);

	if (nAge >= 20)
		printf("당신의 나이는 %d세 입니다.\n", nAge);

	puts("End");

	return 0;
}