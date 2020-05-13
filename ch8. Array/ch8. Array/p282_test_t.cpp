// Q. 2차원 배열 출력구조 변경하기
// 출력 값
// 1,2,3,4		5,1\n6,2\n7,3\n8,4
// 5,6,7,8 =>	6,2
//				7,3
//				8,4
#include<stdio.h>

int main()
{
	int fstArray[2][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
	};

	int secArray[4][2] = { 0 };

	int maxRow = sizeof(secArray) / sizeof(secArray[0]);
	int maxCol = sizeof(secArray[0]) / sizeof(int);

	/*
	------------------------------
	00 01 02 03		10 00
	10 11 12 13  =>	11 01
					12 02
					13 03
	------------------------------
	*/
	int max = 0;
	for (int i = 0; i < maxRow; i++)
	{
		max = sizeof(fstArray) / sizeof(fstArray[0]) - 1;
		for (int j = 0; j < maxCol; j++)
		{
			secArray[i][j] = fstArray[max--][i];
		}
	}

	// 출력
	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			printf("%2d ", secArray[i][j]);
		}
		puts("");
	}

	return 0;

}