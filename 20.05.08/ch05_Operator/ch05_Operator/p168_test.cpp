// 168p
// Q : 토너먼트 방식으로 가장 큰 수 구하기 + 최솟값
#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0, num3 = 0;
	int maxNum = 0, minNum = 0;

	printf("세 정수 입력 : ");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	maxNum = num1 > num2 ? num1 : num2;
	maxNum = maxNum > num3 ? maxNum : num3;
	printf("Max : %d\n", maxNum);
	
	minNum = num1 < num2 ? num1 : num2;
	minNum = minNum < num3 ? minNum : num3;
	printf("Min : %d\n", minNum);

	return 0;
}