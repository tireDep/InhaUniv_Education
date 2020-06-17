#include<stdio.h>

#define ARRSIZE 5

void CalcArr(int calcArr[ARRSIZE][ARRSIZE]);
void PrintfArr(int printArr[ARRSIZE][ARRSIZE], int maxRow, int maxCol);

int main()
{
	int numArr[ARRSIZE][ARRSIZE] = { 0 };
	int maxRow = sizeof(numArr) / sizeof(numArr[0]);
	int maxCol = sizeof(numArr[0]) / sizeof(int);

	CalcArr(numArr);
	PrintfArr(numArr, maxRow, maxCol);

	return 0;

}

void CalcArr(int calcArr[ARRSIZE][ARRSIZE])
{
	int maxCnt = ARRSIZE * 2;	// 전체 진행 횟수
	int i = 0, j = 0;	// 좌표
	int change = 0;	// 증감 값
	int maxChange = 0;	// 최대 진행 횟수
	int startNum = 0;	// j 시작 값
	int num = 1;	// 저장할 값

	while (i<maxCnt)
	{
		j = startNum;
		while (j <= maxChange)
		{
			if (i % 2 == 0)	// 짝수일 때
			{
				calcArr[maxChange - change][j] = num++;
			}
			else // 홀수일 때
			{
				calcArr[j][maxChange - change] = num++;
			}

			j++;
			change++;
		}
		i++;
		change = 0;

		if (i >= ARRSIZE)	// 진행횟수가 절반보다 클 경우, 최대 횟수 감소 및 시작좌표 증가
		{
			maxChange = ARRSIZE - 1;
			startNum++;
		}
		else
		{
			maxChange++;
		}
	}

	return;
}

void PrintfArr(int printArr[ARRSIZE][ARRSIZE], int maxRow, int maxCol)
{
	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			printf("%2d ", printArr[i][j]);
		}
		puts("");
	}

	return;
}