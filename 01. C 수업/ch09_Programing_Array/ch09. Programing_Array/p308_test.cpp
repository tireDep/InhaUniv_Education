// 308p
// Q. 지그재그로 2차원 배열 채우기
#include<stdio.h>

int main()
{
	int cnt = 1;
	int nArray[5][5] = { 0 };

	int maxRow = sizeof(nArray) / sizeof(nArray[0]);
	int maxCol = sizeof(nArray[0]) / sizeof(int);

	/*
	for (int i = 0; i < maxRow; i++)
	{
		if (i % 2 == 0) // 짝수 행
		{
			for (int j = 0; j < maxCol; j++)
			{
				nArray[i][j] = cnt++;
			}
		}
		else  // 홀수 행
		{
			for (int j = maxCol-1; j >= 0; j--)
			{
				nArray[i][j] = cnt++;
			}
		}
	}
	*/

	bool checkPos = true;	// 방향 확인
	for (int i = 0; i < maxRow; i++)
	{
		if (!checkPos)
		{
			for (int j = 0; j < maxCol; j++)
			{
				nArray[i][j] = cnt++;
				checkPos = true;
			}
		}
		else
		{
			for (int j = maxCol - 1; j >= 0; j--)
			{
				nArray[i][j] = cnt++;
				checkPos = false;
			}
		}
	}
	

	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			printf("%2d ", nArray[i][j]);
		}
		puts("");
	}

	puts("");
	return 0;

}

/*
여러 방법
-> 짝수 줄, 홀수 줄 구분해서 출력
-> 플래그 세워서 풀기

bool flag
-> true == 1
-> false == 0
--> 1byte(8bit)
*/