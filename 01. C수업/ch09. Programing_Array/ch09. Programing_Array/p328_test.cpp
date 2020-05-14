// 328p
// Q. 다음과 같은 형태 출력
// 01 10 11 20 21
// 02 09 12 19 22
// 03 08 13 18 23
// 04 07 14 17 24
// 05 06 15 16 25

#include<stdio.h>

#define arrSize 5

int main()
{
	int num = 1;
	int nArr[arrSize][arrSize] = { 0 };

	int maxSize = sizeof(nArr) / sizeof(nArr[0]);

	for (int i = 0; i < maxSize; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < maxSize; j++)
			{
				nArr[j][i] = num++;
			}
		}
		else
		{
			for (int j = maxSize-1; j >= 0; j--)
			{
				nArr[j][i] = num++;
			}
		}
	}

	// 출력
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			printf("%2d ", nArr[i][j]);
		}
		puts("");
	}

	return 0;
}