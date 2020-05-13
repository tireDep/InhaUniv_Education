// Q. 주어진 형태 출력
// 4			3 
// *   *		* *
//  * *			 *
//  * *			* *
// *   *
#include<stdio.h>

int main()
{
	int input;
	printf("숫자 입력 : ");
	scanf_s("%d", &input);

	int center = input / 2;
	int upPos = 0;
	int downPos = 1;
	int lastPos = input - 1;

	int checkNum = 0;
	if (input % 2 == 0)
	{
		checkNum = 1;
	}

	for (int i = 0; i < input; i++)
	{
		upPos = i;
		
		for (int j = 0; j < input; j++)
		{
			if (i <= center)
			{
				if (j==upPos)
				{
					printf("* ");
				}
				else if (j == lastPos)
				{
					printf("* ");
					lastPos--;
				}
				else
				{
					printf("  ");
				}
			}
			else
			{
				if (j == center -checkNum - downPos || j == center + downPos)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}

				if (j == input - 1)
				{
					downPos++;
				}
			}
		}
		puts("");
	}
	return 0;
}
/*
---------------------------------
같은 인덱스 일 때
---------------------------------
*/