// Q. ���丮��
#include<stdio.h>

int main()
{
	int input = 0;
	printf("���� �Է� : ");
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

	printf("\n��� �� : %d\n", result);

	return 0;
}