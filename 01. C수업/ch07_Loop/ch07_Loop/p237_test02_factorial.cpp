// Q. 팩토리얼
#include<stdio.h>

int main()
{
	int input = 0;
	printf("숫자 입력 : ");
	scanf_s("%d", &input);

	int result = 0;
	/*for (int i = 0; i <= input; i++)
	{
		if (i == 0)
		{
			i = 1;
			result = 1;
		}
		else
		{
			result *= i;
		}
	}*/
	result = 1;
	for (int i = input; i > 0; i--)
	{
		result *= i;
	}

	printf("\n결과 값 : %d\n", result);

	return 0;
}