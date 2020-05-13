// Q. 2���� �迭�� ��� ���� ���� ����ϱ� + Ȯ�强 �߰�
#include<stdio.h>

int main()
{
	int aList[5][6]=
	{
		{10,20,30,40},
		{40,50,60,70},
		{80,90,100,110}
	};
	int i = 0, j = 0;

	// ----- �ڵ� �ۼ� -----

	int maxRow = sizeof(aList) / sizeof(aList[0]);
	int maxCol = sizeof(aList[0]) / sizeof(int);

	for (i = 0; i < maxRow; ++i)
	{
		for (j = 0; j < maxCol; ++j)
		{
			if (j != maxCol - 1)	// �� ������ ��
			{
				aList[i][maxCol - 1] += aList[i][j];
			}
			
			if (i == maxRow - 1)	// �� ������ ��
			{
				for (int k = 0; k < maxRow; k++)
				{
					aList[i][j] += aList[i - k][j];
				}	// for()_k
			}
		}	// for()_j
	}	// for()_i
	
	/*
	------------------------------------------------------------
	sizeof(aList) / sizeof(int));	// 2���� �迭 ��ü ũ��
	sizeof(aList) / sizeof(aList[0]));	// 2���� �迭 �� ũ��
	sizeof(aList[0]) / sizeof(int));	// 2���� �迭 �� ũ��
	------------------------------------------------------------
	*/

	// ----- �ڵ� �ۼ� -----

	for (i = 0; i < maxRow; ++i)
	{
		for (j = 0; j < maxCol; ++j)
		{
			printf("%3d\t", aList[i][j]);
		}
		putchar('\n');
	}

	return 0;
}