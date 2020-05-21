// 442p
// ��������
// - line43 �� �ִ� pList[]�� *pList�� �ٲٱ�
//
// - InitList()
// --> �Է¹޴´�� �޸� ���Ҵ� �ϰ� ũ�⸦ ����ϴ� ���·� �ٲٱ�
// --> ���� �Է�, ���� ������ �Է� �޵��� �ϰ� ������ �ԷµǸ� �Է� ����
//
// - �� �Լ� ȣ�� �� �ι�° ���� 5�� ������ �ٲپ� �� �� 

#include<stdio.h>
#include<stdlib.h>

void InitList(int *pList, int *size);
void SortList(int *pList, int *size);
void PrintList(int *pList, int *size);

int main()
{
	int *pList = (int *)malloc(sizeof(int));

	int size = 0;

	InitList(pList, &size);
	SortList(pList, &size);
	PrintList(pList, &size);

	if (pList != NULL)
	{
		free(pList);
	}

	return 0;
}

void InitList(int *pList, int *size)
{
	// �Է¹޴´�� ���Ҵ�, ���� ������ �Է�
	int inputNum = 0;
	// int arrSize = *size;

	while (1)
	{
		/*
		printf("������ �Է��ϼ��� : ");
		scanf_s("%d", &inputNum);
		if (inputNum < 0)
		{
			break;
		}

		pList[*size] = inputNum;
		(*size)++;
		pList = (int *)realloc(pList, sizeof(int) * (*size + 1));
		*/
		
		printf("������ �Է��ϼ��� : ");
		scanf_s("%d", &pList[*size]);
		// printf("%p %p\n", pList[*size], &pList[*size]);
		if (pList[*size] < 0)
		{
			break;
		}
		(*size)++;
		pList = (int *)realloc(pList, sizeof(int) * (*size + 1));
	}

}

void SortList(int *pList, int *size)
{
	int index;
	int temp;

	for (int i = 0; i < *size - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < *size; j++)
		{
			index = pList[index] > pList[j] ? j : index;
		}
		temp = pList[i];
		pList[i] = pList[index];
		pList[index] = temp;
	}
}

void PrintList(int *pList, int *size)
{
	for (int i = 0; i < *size; i++)
	{
		printf("%d ", *(pList + i));
	}
	puts("");
}