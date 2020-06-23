// p170

#include<stdio.h>

int Gcd(int x, int y);

int main()
{
	int x, y;
	puts("두 정수의 최대 공약수를 구합니다.");
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &x);
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &y);
	printf("최대공약수는 %d입니다.\n", Gcd(x, y));

	return 0;
}

int Gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return Gcd(y, x%y);
}