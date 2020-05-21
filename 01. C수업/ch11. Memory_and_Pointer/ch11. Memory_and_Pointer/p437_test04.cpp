// 437p
// Q. ���ͳݿ��� strrev() �Լ��� ������� ���� ã�ƺ��� 
// �� �Լ��� ������ ����� ������ �� �ִ� MyStrrev() �Լ��� �ۼ��ϼ���

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 128

void CheckError(char *mem);
void MyStrrev(char *input, char *result);

int main()
{
	char *inputString = NULL;
	inputString = (char *)malloc(sizeof(char) * SIZE);
	CheckError(inputString);

	char *resultString = NULL;
	resultString = (char *)malloc(sizeof(char) * SIZE);
	CheckError(resultString);

	printf("���ڿ� �Է� : ");
	gets_s(inputString, SIZE);

	MyStrrev(inputString, resultString);

	printf("������ ���ڿ� : %s\n", resultString);

	if (inputString != NULL)
	{
		free(inputString);
	}

	if (resultString != NULL)
	{
		free(resultString);
	}

	return 0;
}

void CheckError(char *mem)
{
	if (mem == NULL)
	{
		puts("Error!");
	}
}

void MyStrrev(char *input, char *result)
{
	int i = 0;
	for (i = 0; i < strlen(input); i++)
	{
		result[i] = input[strlen(input) - i - 1];
	}
	result[i] = '\0';
	return;
}