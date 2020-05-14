// Q. 구구단에서 한 단만 출력하기
// 정렬하기
#include<stdio.h>

int main()
{
	int input;
	printf("정수 입력 : ");
	scanf_s("%d", &input);
	
	if (2 > input || 9 < input)
	{
		puts("Error!");
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			if (i != 0)
			{
				printf("%d * %d = %2d\n", input, i, input*i); // %2d : 정렬
			}
		}
	}
	
	/*
	if (2 > input || 9 < input)
	{
		puts("Error!");
	}

	else
	{
		int cnt = 1;
		while (cnt < 10)
		{
			printf("%d * %d = %2d\n", input, cnt, input*cnt); // %2d : 정렬
			cnt++;
		}
	}
	*/

	return 0;
}