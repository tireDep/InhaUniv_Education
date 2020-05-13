// Q. 주어진 형태 출력_개선ver
// 출력값
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

	int crossCheck = input - 1;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (j == i || j == crossCheck - i)
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

	return 0;
}
/*
-----------------------------------------------
접근 방법
[규칙 세우기]
- (x, y) 숫자가 같으면 출력됨(↘ 방향)
- (y, 입력값 - x) 일 때 출력됨(↙ 방향)

ex) 3일 경우 출력 위치
(0,0)	(0,2)
	(1,1)
(2,0)	(2,2)
-----------------------------------------------
*/