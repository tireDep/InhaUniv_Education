// 308p
// Q. ������׷� 2���� �迭 ä���
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
		if (i % 2 == 0) // ¦�� ��
		{
			for (int j = 0; j < maxCol; j++)
			{
				nArray[i][j] = cnt++;
			}
		}
		else  // Ȧ�� ��
		{
			for (int j = maxCol-1; j >= 0; j--)
			{
				nArray[i][j] = cnt++;
			}
		}
	}
	*/

	bool checkPos = true;	// ���� Ȯ��
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
���� ���
-> ¦�� ��, Ȧ�� �� �����ؼ� ���
-> �÷��� ������ Ǯ��

bool flag
-> true == 1
-> false == 0
--> 1byte(8bit)
*/