// Q. 임의의 정수를 입력 받은 후 그 수 만큼 반복해서 숫자를 입력받아서
// 입력받은 전체 수와 합을 출력하는 프로그램을 작성하시오

#include<stdio.h>
#include<stdlib.h>

int Input(int inputCnt, int *numArr);
void PrintArr(int inputCnt, int *numArr, int result);

int main()
{
	int inputCnt;
	do
	{
		printf("배열의 크기 입력 : ");
		scanf_s("%d", &inputCnt);
	} while (inputCnt < 1);

	int *numArr = (int *)malloc(sizeof(int) * inputCnt);
	int result = Input(inputCnt, numArr);

	PrintArr(inputCnt, numArr, result);
	free(numArr);
	
	return 0;
}

int Input(int inputCnt, int *numArr)
{
	int inputNum;
	int result = 0;
	for (int i = 0; i < inputCnt; i++)
	{
		printf("입력 no.%d : ", i + 1);
		scanf_s("%d", &inputNum);

		*(numArr + i) = inputNum;
		result += inputNum;
	}

	return result;
}

void PrintArr(int inputCnt, int *numArr, int result)
{
	printf("\n입력받은 수는 [ ");
	for (int i = 0; i < inputCnt; i++)
	{
		printf("%d ", numArr[i]);
	}
	printf("] 이고 합은 [ %d ] 이다.\n", result);
}