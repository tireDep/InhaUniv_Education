// 437p
// Q. 인터넷에서 strrev() 함수의 사용방법에 대해 찾아보고 
// 이 함수와 동일한 기능을 수행할 수 있는 MyStrrev() 함수를 작성하세요

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

	printf("문자열 입력 : ");
	gets_s(inputString, SIZE);

	MyStrrev(inputString, resultString);

	printf("뒤집은 문자열 : %s\n", resultString);

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