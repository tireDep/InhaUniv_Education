// Q. ������ ���
#include<stdio.h>
#define arraySize 10

int main()
{
	int nArray[arraySize][arraySize] = { 0 };
	int num = 1;
	int check = 1;

	int maxSize = sizeof(nArray) / sizeof(nArray[0]);	// �ִ����

	int i = 0, j = -1;	// ���� ����

	// ���� ���
	while (maxSize>0)
	{
		/*
		- i��ǥ, j��ǥ�� ����
			-> j��ǥ ���� �����ϱ⶧����, -1�� �����ؾ� ��( -1(j) + 1(check) = 0)

		- ������ȯ -1 / 1
		- ��ġ�� pos�� �̵�
		- �ι�° �̵����� (�迭ũ�� - �̵�Ƚ��) * 2
		- �ִ� ���̰� ����ɼ��� ������

		ex) 5x5
			5-4-4-3-3-2-2-1-1
		*/

		for (int pos = 0; pos < maxSize; pos++)
		{
			j = j + check;
			nArray[i][j] = num++;
		}

		maxSize--;	// �ִ� ���� ����

		for (int pos = 0; pos < maxSize; pos++)
		{
			i = i + check;
			nArray[i][j] = num++;
		}

		check = -check;	// ���� ��ȯ
	}

	// ���
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