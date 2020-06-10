// Q. ������ ������ �Է� ���� �� �� �� ��ŭ �ݺ��ؼ� ���ڸ� �Է¹޾Ƽ�
// �Է¹��� ��ü ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�

#include<stdio.h>
#include<stdlib.h>

int Input(int inputCnt, int *numArr);
void PrintArr(int inputCnt, int *numArr, int result);

int main()
{
	int inputCnt;
	do
	{
		printf("�迭�� ũ�� �Է� : ");
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
		printf("�Է� no.%d : ", i + 1);
		scanf_s("%d", &inputNum);

		*(numArr + i) = inputNum;
		result += inputNum;
	}

	return result;
}

void PrintArr(int inputCnt, int *numArr, int result)
{
	printf("\n�Է¹��� ���� [ ");
	for (int i = 0; i < inputCnt; i++)
	{
		printf("%d ", numArr[i]);
	}
	printf("] �̰� ���� [ %d ] �̴�.\n", result);
}