// Q. n x n ũ���� ����� �־�����. 
// �̶�, �־��� ����� i�࿡ �ִ� ��� ���ڿ� j���� �ִ� ��� ������ ���� i�� j���� ���� ���ο� ����� ���Ϸ��� �Ѵ�.
// ��, ���������� ���ڴ� �� ���� ���ؾ� �Ѵ�.
// ex) 3x3
// 1 2 3	  17 19 21
// 4 5 6  =>  23 25 27
// 7 8 9	  29 31 33
// 1�� 1���� ���� 17 return �ϴ� �Լ� �ۼ�
// ���ѻ��� 
// 1. 2���� �迭�� n x n�� ũ���� ����� ��Ÿ����, n�� 3�̻� 50������ �ڿ���
// 2. �� ���Ҵ� 1 �̻� 10,000 ������ �ڿ���

/*
�ʿ�
- �迭�� ũ�⸦ �Է��ϰ�, ������ �� ����
- ��� ���� �� ��� & ��갪 ����
- ���
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

// �� �Է� �Լ�
void InputNumArr(int numArr[][arrSize], int maxSize)
{
	int inputStartNum;

	while (1)
	{
		printf("����� ���۰��� �Է��Ͻÿ� : ");
		scanf_s("%d", &inputStartNum);

		if (inputStartNum >= 1 && inputStartNum <= 10000)
		{
			break;
		}
	}

	// ��� �� �Է�
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			numArr[i][j] = inputStartNum++;
		}
	}

}

// ��� �Լ�
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

		resultArr[i][j] -= numArr[i][j];	// ��, �� �� ���� �� ��ġ�� �κ� ��

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

// ����Լ�
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