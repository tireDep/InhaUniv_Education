// 442p
// 수정사항
// - line43 에 있는 pList[]를 *pList로 바꾸기
//
// - InitList()
// --> 입력받는대로 메모리 재할당 하고 크기를 계산하는 형태로 바꾸기
// --> 무한 입력, 양의 정수만 입력 받도록 하고 음수가 입력되면 입력 종료
//
// - 각 함수 호출 시 두번째 인자 5는 변수로 바꾸어 줄 것 

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
	// 입력받는대로 재할당, 양의 정수만 입력
	int inputNum = 0;
	// int arrSize = *size;

	while (1)
	{
		/*
		printf("정수를 입력하세요 : ");
		scanf_s("%d", &inputNum);
		if (inputNum < 0)
		{
			break;
		}

		pList[*size] = inputNum;
		(*size)++;
		pList = (int *)realloc(pList, sizeof(int) * (*size + 1));
		*/
		
		printf("정수를 입력하세요 : ");
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