// 328p
// Q2. 반시계방향 달팽이
#include<stdio.h>

#define arrSize 5

int main()
{
	int num = 1;
	int nArray[arrSize][arrSize] = { 0 };
	
	int maxSize = sizeof(nArray) / sizeof(nArray[0]);
	bool checkR = true, checkD = false;
	int i = 0, j = 5, check = -1;

	while(maxSize > 0)
	{
		for (int pos = maxSize; pos > 0; pos--)
		{
			j = j + check;
			nArray[i][j] = num++;
		}
		
		maxSize--;
		check = -check;

		for (int pos = 0; pos < maxSize; pos++)
		{
			i = i + check;
			nArray[i][j] = num++;
		}
	}

	// 출력
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			printf("%2d ", nArray[i][j]);
		}
		puts("");
	}

	return 0;
}