// Q. 2차원 배열의 행과 열의 총합 계산하기 + 확장성 추가
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

	// ----- 코드 작성 -----

	int maxRow = sizeof(aList) / sizeof(aList[0]);
	int maxCol = sizeof(aList[0]) / sizeof(int);

	for (i = 0; i < maxRow; ++i)
	{
		for (j = 0; j < maxCol; ++j)
		{
			if (j != maxCol - 1)	// 맨 마지막 열
			{
				aList[i][maxCol - 1] += aList[i][j];
			}
			
			if (i == maxRow - 1)	// 맨 마지막 행
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
	sizeof(aList) / sizeof(int));	// 2차원 배열 전체 크기
	sizeof(aList) / sizeof(aList[0]));	// 2차원 배열 행 크기
	sizeof(aList[0]) / sizeof(int));	// 2차원 배열 열 크기
	------------------------------------------------------------
	*/

	// ----- 코드 작성 -----

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