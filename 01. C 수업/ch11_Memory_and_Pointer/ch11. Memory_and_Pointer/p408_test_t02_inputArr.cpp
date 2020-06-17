// Q. Ư�� ����(-1)�� �ԷµǱ� ������ ������ �Է¹ް�, 
// �Է¹��� �������� �����ؼ� ���� �� �� ���� �ĸ� ����� ��
// ����
// - �迭 ��� ����
// - ������, �����Ҵ� �̿�

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include<Windows.h>	// �ܼ�â ����

void Sort(int *numArr);
void PrintArr(int *numArr, char *printString);

int main()
{
	system("mode con cols=50 lines=25");	// �ܼ�â ũ�� ����
	
	COORD coord;
	coord.X = 25 / 2;
	coord.Y = 25 / 2;
	// �ܼ�â �߾� ���

	int inputNum = 0;
	int cnt = 0;
	int *numArr = (int *)malloc(sizeof(int));

	while (1)
	{
		system("cls");	// ȭ�� ����
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	// �ܼ�â �߾� ���

		printf("���ڸ� �Է��Ͻÿ� : ");
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

	PrintArr(numArr, "���� �� ����");
	Sort(numArr);
	PrintArr(numArr, "���� �� ����");

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