// Q. 달팽이 출력
#include<stdio.h>
#define arraySize 10

int main()
{
	int nArray[arraySize][arraySize] = { 0 };
	int num = 1;
	int check = 1;

	int maxSize = sizeof(nArray) / sizeof(nArray[0]);	// 최대길이

	int i = 0, j = -1;	// 누적 변수

	// 실제 계산
	while (maxSize>0)
	{
		/*
		- i좌표, j좌표가 누적
			-> j좌표 부터 시작하기때문에, -1로 설정해야 함( -1(j) + 1(check) = 0)

		- 방향전환 -1 / 1
		- 위치는 pos로 이동
		- 두번째 이동부터 (배열크기 - 이동횟수) * 2
		- 최대 길이가 진행될수록 감소함

		ex) 5x5
			5-4-4-3-3-2-2-1-1
		*/

		for (int pos = 0; pos < maxSize; pos++)
		{
			j = j + check;
			nArray[i][j] = num++;
		}

		maxSize--;	// 최대 길이 감소

		for (int pos = 0; pos < maxSize; pos++)
		{
			i = i + check;
			nArray[i][j] = num++;
		}

		check = -check;	// 방향 전환
	}

	// 출력
	for (int i = 0; i < arraySize; i++) 
	{
		for (int j = 0; j < arraySize; j++)
		{
			printf("%d\t", nArray[i][j]);
		}
		printf("\n");
	}

	return 0;
}