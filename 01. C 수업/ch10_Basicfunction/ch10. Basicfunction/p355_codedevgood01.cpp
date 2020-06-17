// 355p
#include<stdio.h>

#define arrSize 10

void InitList(int *pList, int nSize);
void SortList(int *pList, int nSize);
void PrintList(int *pList, int nSize);

int main()
{
	int aList[arrSize] = { 0 };

	InitList(aList, arrSize);
	SortList(aList, arrSize);
	PrintList(aList, arrSize);

	return 0;
}

void InitList(int *pList, int nSize)
{
	int i = 0;
	for (i = 0; i < nSize; i++)
	{
		printf("정수를 입력하세요 : ");
		scanf_s("%d", &pList[i]);
	}

	return;
}

void SortList(int *pList, int nSize)
{
	int temp;
	for (int i = 0; i < nSize - 1; i++)
	{
		for (int j = i; j < nSize; j++)
		{
			if (pList[i] > pList[j])
			{
				temp = pList[i];
				pList[i] = pList[j];
				pList[j] = temp;
			}
		}
	}

	return;
}

void PrintList(int *pList, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		printf("%d ", pList[i]);
	}
	puts("");

	return;
}