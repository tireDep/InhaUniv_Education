// Q. [9][9]배열 선언, 구구단 연산의 결과값을 배열에 저장한 후,
// 사용자로부터 입력을 받아 해당 단만 출력
#include<stdio.h>

int main()
{
	int calcArray[9][9] = { 0 };

	for (int i = 0; i < 9; i++)
	{
		if (i < 2)
		{
			continue;
		}

		for (int j = 0; j < 9; j++)
		{
			calcArray[i][j] = i * (j + 1);
		}
	}
	for (int k = 0; k < 9; k++)
	{
		calcArray[9][k] = 9 * (k + 1);
	}
	// 구구단 계산
	
	int input=100;
	int check = -1;
	while(1)
	{
		printf("출력할 단 : ");
		scanf_s("%d", &input);

		printf("[%d단]\n", input);
		for (int i = 0; i < 9; i++)
		{
			printf("%d * %d = %2d\n", input, i + 1, calcArray[input][i]);
		}
		puts("");

		scanf_s("%d", &check);
		if (check == 0)
		{
			break;
		}
	}

	puts("구구단 종료");

	return 0;
}