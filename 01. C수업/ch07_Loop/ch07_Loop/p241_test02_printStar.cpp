// Q. 피라미드 + 마름모 출력
#include<stdio.h>

int main()
{
	int input = 0;
	
	// 피라미드 출력
	puts("[피라미드 출력]");
	printf("줄 수 입력 : ");
	scanf_s("%d", &input);

	int maxStar = 1 + 2 * (input - 1); 
	// 별 개수가 1-3-5-7-9 순으로 증가함!
	int pCenter = maxStar / 2;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= maxStar; j++)
		{
			if (j >= pCenter - i && j <= pCenter + i)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		puts("");
	}

	input = 0;
	printf("\n");

	// 마름모 출력
	puts("[마름모 출력]");
	while (input % 2 == 0)
	{
		printf("줄 수 입력(홀수) : ");
		scanf_s("%d", &input);

		if (input % 2 == 0)
		{
			puts("\n홀수를 입력하시오\n");
		}
	}

	int center = input / 2;
	int cnt = center - 1;
	
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (center >= i)	// 위 세모
			{
				if (j >= center - i && j <= center + i)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}
			}
			else  // 아래 세모
			{
				if (j >= center - cnt && j <= center + cnt)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}

				if (j == input -1)
				{
					cnt--;
				}
			}
		}
		puts("");
	}

	return 0;
}