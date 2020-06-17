// Q. 특정 정수(-1)가 입력되기 전까지 정수를 입력받고, 
// 입력받은 정수들을 정렬해서 정렬 전 과 정렬 후를 출력할 것
// 조건
// - 배열 사용 금지
// - 포인터, 동적할당 이용

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include<Windows.h>	// 콘솔창 관련

void Sort(int *numArr);
void PrintArr(int *numArr, char *printString);

int main()
{
	system("mode con cols=50 lines=25");	// 콘솔창 크기 조절
	
	COORD coord;
	coord.X = 25 / 2;
	coord.Y = 25 / 2;
	// 콘솔창 중앙 출력

	int inputNum = 0;
	int cnt = 0;
	int *numArr = (int *)malloc(sizeof(int));

	while (1)
	{
		system("cls");	// 화면 삭제
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	// 콘솔창 중앙 출력

		printf("숫자를 입력하시오 : ");
		scanf_s("%d", &inputNum);

		if (inputNum == -1)
		{
			break;
		}
		
		*(numArr + cnt) = inputNum;
		cnt++;

		numArr = (int *)realloc(numArr, sizeof(int) * (cnt + 1));
		if (numArr == NULL)
		{
			puts("ERROR!");
			return 0;
		}
		
	}

	PrintArr(numArr, "정렬 전 숫자");
	Sort(numArr);
	PrintArr(numArr, "정렬 후 숫자");

	if (numArr != NULL)
	{
		free(numArr);
	}

	return 0;
}

void Sort(int *numArr)
{
	int index = 0;
	int temp = 0;
	for (int i = 0; i < _msize(numArr)/sizeof(int); i++)
	{
		index = i;
		for (int j = i+1; j < _msize(numArr) / sizeof(int) - 1; j++)
		{
			index = numArr[index] < numArr[j] ? index : j;
		}
		temp = numArr[i];
		numArr[i] = numArr[index];
		numArr[index] = temp;
	}

	return;
}	// void Sort()

void PrintArr(int *numArr, char *printString)
{
	printf("\n%s\n", printString);

	for (int i = 0; i < _msize(numArr) / sizeof(int) - 1; i++)
	{
		printf("%d ", *(numArr + i));
	}
	puts("");

	return;
}	// void PrintArr