// 437p
// Q, 매개변수로 char *형 자료를 받아서 문자열의 길이를 계산해 반환하는 함수를 작성하세요.
// 함수의 이름은 GetLength()로 합니다.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int GetLength(char *string);

int main()
{
	char *inputString = NULL;
	inputString = (char *)malloc(128);
	if (inputString == NULL)
	{
		puts("Error!");
		return 0;
	}
	
	int result;
	printf("문자열 입력 : ");
	gets_s(inputString, strlen(inputString));	
	// malloc, realloc 등 크기는 _msize() 이용, but window에서만 사용 가능
	// strlen(), 매직 넘버 등 여러 방법이 있음

	result = GetLength(inputString);

	printf("문자열의 길이 : %d\n", result);

	if (inputString != NULL)
	{
		free(inputString);
	}
}

int GetLength(char *string)
{
	int cnt = 0;

	while (*(string + cnt) != '\0')
	{
		cnt++;
	}

	return cnt;
}