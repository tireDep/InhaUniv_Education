// Q. 직각 삼각형 출력
// 정방향, 역방향(좌우반전)
#include<stdio.h>

int main()
{
	int input;

	// 정방향
	printf("숫자 입력 : ");
	scanf_s("%d", &input);
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("* ");
		}
		puts("");
	}

	// 역방향(좌우반전)
	printf("\n숫자 입력 : ");
	scanf_s("%d", &input);
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= input; j++)
		{
			if (j >= input - i)
			{
				printf(" *");
			}
			else
			{
				printf("  ");
			}
		}
		puts("");
	}
}