// Q. n x n ũ���� ����� �� ĭ�� 1���� n^2 ������ ���ڰ� ������� �������� ä���� �ֽ��ϴ�.
// ex)
//  1  2  6  7 15
//  3  5  8 14 16
//  4  9 13 17 22
// 10 12 18 21 23
// 11 19 20 24 25
// �� �� r��, c���� ĭ�� � ���ڰ� �����ִ��� ���Ϸ��� �Ѵ�
// ���� ��� ������ r = 3, c = 2 => 3�� 2�� : 9
// ������� ����� ũ�� n, ���� ��ġ r, ���� ��ġ c�� �Ű� ������ �־��� ��, 
// n x n ũ���� ����� r�� c���� �ִ� ���ڰ� ���ϵǵ��� �Լ� ����
// [����]
// 1. n�� 1 �̻� 10,000,000 ������ �ڿ���
// 2. r, c �� 1 �̻� n ������ �ڿ���
// 3. ������ 2^31 - 1 ���� Ŀ�� �� ������ ����

/*
�ʿ�
������� ��� �Լ�
��, �� ��ġ �Է� �ް� ���
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
				if (cnt % 2 == 0) // ¦�� ��° ���
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
				else  // Ȧ�� ��° ���
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
				if ((checkDown) % 2 == 0) // ¦�� ��° ���
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
				else  // Ȧ�� ��° ���
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

// ���
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