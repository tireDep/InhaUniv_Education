// Q. n x n 크기의 행렬이 주어진다. 
// 이때, 주어진 행렬의 i행에 있는 모든 숫자와 j열에 있는 모든 숫자의 합이 i행 j열의 값인 새로운 행렬을 구하려고 한다.
// 단, 교차지점의 숫자는 한 번만 더해야 한다.
// ex) 3x3
// 1 2 3	  17 19 21
// 4 5 6  =>  23 25 27
// 7 8 9	  29 31 33
// 1행 1열의 값은 17 return 하는 함수 작성
// 제한사항 
// 1. 2차원 배열로 n x n의 크기의 행렬을 나타내며, n은 3이상 50이하의 자연수
// 2. 각 원소는 1 이상 10,000 이하의 자연수

/*
필요
- 배열의 크기를 입력하고, 임의의 값 저장
- 행과 열의 값 계산 & 계산값 저장
- 출력
*/

#include<stdio.h>

#define arrSize 3

void InputNumArr(int numArr[][arrSize], int maxSize);
void CalcArr(int numArr[][arrSize], int resultArr[][arrSize], int maxSize);
void PrintArr(int resultArr[][arrSize], int maxSize);

int main()
{
	int numArr[arrSize][arrSize] = { 0 };
	int resultArr[arrSize][arrSize] = { 0 };
	int maxSize = sizeof(numArr) / sizeof(numArr[0]);
	
	InputNumArr(numArr, maxSize);
	CalcArr(numArr, resultArr, maxSize);
	// PrintArr(resultArr,maxSize);
}

// 값 입력 함수
void InputNumArr(int numArr[][arrSize], int maxSize)
{
	int inputStartNum;

	while (1)
	{
		printf("행렬의 시작값을 입력하시오 : ");
		scanf_s("%d", &inputStartNum);

		if (inputStartNum >= 1 && inputStartNum <= 10000)
		{
			break;
		}
	}

	// 행렬 값 입력
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			numArr[i][j] = inputStartNum++;
		}
	}

}

// 계산 함수
void CalcArr(int numArr[][arrSize], int resultArr[][arrSize], int maxSize)
{
	/*
	resultArr[posX][posY] = numArr[i][j - 0] + numArr[i][j + 1] + numArr[i][j + 2] + numArr[i + 1][j + 0] + numArr[i + 2][j + 0];
	resultArr[posX][posY] = numArr[i][j - 1] + numArr[i][j + 0] + numArr[i][j + 1] + numArr[i + 1][j + 1] + numArr[i + 2][j + 1];
	resultArr[posX][posY] = numArr[i][j - 2] + numArr[i][j - 1] + numArr[i][j + 0] + numArr[i + 1][j + 2] + numArr[i + 2][j + 2];
	*/

	int i = 0, j = 0;
	int check = 0;

	while (1)
	{
		for (int posX = 0; posX < maxSize; posX++)
		{
			resultArr[i][j] += numArr[i][posX];
		}

		for (int posY = 0; posY < maxSize; posY++)
		{
			resultArr[i][j] += numArr[posY][j];
		}

		resultArr[i][j] -= numArr[i][j];	// 행, 열 다 더한 후 겹치는 부분 뺌

		j++;
		if (j >= arrSize)
		{
			j = 0;
			i++;
		}

		if (i == arrSize)
			break;
	}

	return PrintArr(resultArr, maxSize);
}

// 출력함수
void PrintArr(int resultArr[][arrSize], int maxSize)
{
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			printf("%2d ", resultArr[i][j]);
		}
		puts("");
	}
}