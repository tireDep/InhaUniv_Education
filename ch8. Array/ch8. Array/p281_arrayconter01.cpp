// 281p
#include<stdio.h>

int main()
{
	int aList[3][4] = { 0 };
	int i = 0, j = 0, nCounter = 0;

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			aList[i][j] = ++nCounter;
		}
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			printf("%d\t", aList[i][j]);
		}
		putchar('\n');
	}

	return 0;
}