// 다른 사람 달팽이 코드!!
#include <conio.h>
#include<stdio.h>

#define on 1
#define off 0

int main()
{
	int aList[5][5] = { 0 };
	int i = 0, j = 0, count = 0, nDotPoint = 0;
	bool hFlag = off, vFlag = off;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (vFlag == off && hFlag == off)
			{
				if (aList[0 + nDotPoint][j] == 0) aList[0 + nDotPoint][j] = ++count;
				if (j == 4)
				{
					vFlag = on;
					break;
				}
			}

			if (vFlag == off && hFlag == on)
			{
				if (aList[4 - j][0 + nDotPoint] == 0) aList[4 - j][0 + nDotPoint] = ++count;
				if (j == 4)
				{
					hFlag = off;
					nDotPoint++;
					break;
				}
			}

			if (vFlag == on && hFlag == off)
			{
				if (aList[j][4 - nDotPoint] == 0) aList[j][4 - nDotPoint] = ++count;
				if (j == 4)
				{
					hFlag = on;
					break;
				}
			}

			if (vFlag == on && hFlag == on)
			{
				if (aList[4 - nDotPoint][4 - j] == 0) aList[4 - nDotPoint][4 - j] = ++count;
				if (j == 4)
				{
					vFlag = off;
					break;
				}
			}

		}

	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d\t", aList[i][j]);
		}

		putchar('\n');
	}


	putchar('\n');

	return 0;
}
