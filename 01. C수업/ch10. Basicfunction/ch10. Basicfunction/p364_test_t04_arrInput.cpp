// Q. n x n 크기의 행렬이 각 칸의 1부터 n^2 까지의 숫자가 지그재그 방향으로 채워져 있습니다.
// ex)
//  1  2  6  7 15
//  3  5  8 14 16
//  4  9 13 17 22
// 10 12 18 21 23
// 11 19 20 24 25
// 이 때 r행, c열의 칸에 어떤 숫자가 젹혀있는지 구하려고 한다
// 예를 들어 위에서 r = 3, c = 2 => 3행 2열 : 9
// 지그재그 행렬의 크기 n, 행의 위치 r, 열의 위치 c가 매개 변수로 주어질 때, 
// n x n 크기의 행렬의 r행 c열에 있는 숫자가 리턴되도록 함수 구현
// [제한]
// 1. n은 1 이상 10,000,000 이하의 자연수
// 2. r, c 각 1 이상 n 이하의 자연수
// 3. 정답이 2^31 - 1 보다 커질 수 있음에 주의

/*
필요
지그재그 계산 함수
행, 열 위치 입력 받고 출력
*/

#include<stdio.h>

#define arrSize 7

void DrawCross(int maxSize, int numArr[arrSize][arrSize]);
void PrintArr(int maxSize, int numArr[arrSize][arrSize]);

int main()
{
	int numArr[arrSize][arrSize] = { 0 };
	int maxSize = sizeof(numArr) / sizeof(numArr[0]);
	
	DrawCross(maxSize,numArr);

	PrintArr(maxSize,numArr);

	return 0;

}

void DrawCross(int maxSize, int numArr[arrSize][arrSize])
{
	int cnt = 0;
	int checkDown = 0;
	int num = 1;
	int i = 0, j = 0;

	int checkOdd;
	if (arrSize % 2 == 0)
	{
		checkOdd = 1;
	}
	else
	{
		checkOdd = 0;
	}

	while (1)
	{
		if (cnt < arrSize)
		{
			for (int pos = cnt; pos >= 0; pos--)
			{
				if (cnt % 2 == 0) // 짝수 번째 출력
				{
					numArr[i][j] = num++;
					i--;
					j++;

					if (pos == 0)
					{
						j = ++cnt - checkOdd;
						i = 0;
					}
				}
				else  // 홀수 번째 출력
				{
					numArr[i][j] = num++;
					i++;
					j--;

					if (pos == 0)
					{
						i = ++cnt - checkOdd;
						j = 0;
					}
				}
			}
			checkDown = cnt;
			checkDown--;
		}

		else
		{
			for (int pos = checkDown; pos > 0; pos--)
			{
				if ((checkDown) % 2 == 0) // 짝수 번째 출력
				{
					if (pos == maxSize - 1)
					{
						i = 1;
						j = maxSize - 1;
					}

					numArr[i][j] = num++;
					i++;
					j--;

					if (pos == 1)
					{
						checkDown--;
						i = i-- - checkOdd;
						j = cnt - checkDown - checkOdd;
					}
				}
				else  // 홀수 번째 출력
				{
					numArr[i][j] = num++;
					i--;
					j++;

					if (pos == 1)
					{
						checkDown--;
						i = cnt - checkDown - checkOdd;
						j = j-- - checkOdd;
					}
				}
			}
		}

		if (num > arrSize * arrSize)
			break;
	}
}

// 출력
void PrintArr(int maxSize, int numArr[arrSize][arrSize])
{
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			printf("%2d ", numArr[i][j]);
		}
		puts("");
	}
}