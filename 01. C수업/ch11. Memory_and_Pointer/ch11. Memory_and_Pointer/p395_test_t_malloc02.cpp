// Q. �Է°����� �̸� �������� �ʰ� ���ڸ� �Է� ���������� �޸𸮸� �÷����鼭 ��ü ���� ���� ���
// (������ ���α׷� ����) 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void PrintArr(int cnt, int *resultArr, int result);

int main()
{
	int cnt = 0;
	int result = 0;
	int *tempArr = NULL;
	int *resultArr = (int *)malloc(sizeof(int));

	int inputNum;
	int cntCheck = 0;	// �迭ũ�� ���

	while (1)
	{
		cntCheck = cnt + 1;

		printf("���� �Է� : ");
		scanf_s("%d", &inputNum);

		if (inputNum <= -1)
		{
			break;
		}
		else
		{
			/*
			-------------------------------------------------
			����
			temp :	 x  x  o  o | xo oo	oo	oo | ...
			result : x  x  x  o | o	 o	xx	oo | ...

			+) memcpy()�� �迭 ������ ���, ũ��� sizeof(�迭)*�迭ũ��
			-------------------------------------------------
			*/

			tempArr = (int *)malloc(sizeof(int) * cntCheck);

			memcpy(tempArr, resultArr, sizeof(resultArr) * cntCheck);	// tempArr�� �������� ����
			*(tempArr + cnt) = inputNum;	// tempArr�� �Է°� ����

			free(resultArr);	// �޸� ����
			resultArr = (int *)malloc(sizeof(int) * cntCheck);	// resultArr ���Ҵ�

			memcpy(resultArr, tempArr, sizeof(tempArr) * cntCheck);	// resultArr�� �� ����

			result += inputNum;
			cnt++;
		}
		free(tempArr);
	}

	PrintArr(cnt, resultArr, result);
	free(resultArr);
	
	return 0;
}

void CalcArr(int cnt, int *tempArr, int *resultArr, int result)
{
	return;
}	// void CalcArr()

void PrintArr(int cnt, int *resultArr, int result)
{
	printf("\n�Է¹��� ���� [ ");
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", resultArr[i]);
	}
	printf("] �̰� ���� [ %d ] �̴�.\n", result);

	return;
}	// void PrintArr()