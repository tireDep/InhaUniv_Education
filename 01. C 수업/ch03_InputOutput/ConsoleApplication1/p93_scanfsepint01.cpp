// 93p
#include<stdio.h>

int main()
{
	int x = 0, y = 0;

	printf(" 두 정수를 입력하세요. : ");
	scanf_s("%d%d", &x, &y);

	printf("두 수의 합은 '%d'입니다.\n", x + y);

	return 0;
}