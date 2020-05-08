// 186p
// Q : if문을 이용한 최댓값 구하기
#include<stdio.h>

int main()
{
	int input;
	scanf_s("%d", &input);
	
	int max = input;
	scanf_s("%d", &input);
	if (max < input)
	{
		max = input;
	}

	scanf_s("%d", &input);
	if (max < input)
	{
		max = input;
	}

	printf("MAX : %d\n", max);
	return 0;
}