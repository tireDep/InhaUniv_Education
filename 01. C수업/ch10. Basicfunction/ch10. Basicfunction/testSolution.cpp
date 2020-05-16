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
	int maxCnt = ARRSIZE * 2;	// ��ü ���� Ƚ��
	int i = 0, j = 0;	// ��ǥ
	int change = 0;	// ���� ��
	int maxChange = 0;	// �ִ� ���� Ƚ��
	int startNum = 0;	// j ���� ��
	int num = 1;	// ������ ��

	while (i<maxCnt)
	{
		j = startNum;
		while (j <= maxChange)
		{
			if (i % 2 == 0)	// ¦���� ��
			{
				calcArr[maxChange - change][j] = num++;
			}
			else // Ȧ���� ��
			{
				calcArr[j][maxChange - change] = num++;
			}

			j++;
			change++;
		}
		i++;
		change = 0;

		if (i >= ARRSIZE)	// ����Ƚ���� ���ݺ��� Ŭ ���, �ִ� Ƚ�� ���� �� ������ǥ ����
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