#include<stdio.h>

#define ArrayIndex 4
int main()
{
	int aList[ArrayIndex + 1] = { 30,40,10,50,20 };
	int i = 0, j = 0, nTmp = 0;

	// ------- �ڵ��ۼ� -------

	/*
	for (i = 4; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if (aList[j] > aList[j+1])
			{
				nTmp = aList[j];
				aList[j] = aList[j+1];
				aList[j+1] = nTmp;
			}
		}
	}
	*/

	for (i = 0; i < ArrayIndex; i++)
	{
		for (j = 0; j < ArrayIndex - i; j++)
		{
			if (aList[j] > aList[j + 1])
			{
				nTmp = aList[j];
				aList[j] = aList[j + 1];
				aList[j + 1] = nTmp;
			}
		}
	}

	// ------- �ڵ��ۼ� -------

	for (i = 0; i < 5; ++i)
	{
		printf("%d\t", aList[i]);
	}

	putchar('\n');
	return 0;

}

/*
-----------------------------------
���� ���� : �տ��� ���� ���ĵ�
���� ���� : �ڿ��� ���� ���ĵ�
-----------------------------------
*/