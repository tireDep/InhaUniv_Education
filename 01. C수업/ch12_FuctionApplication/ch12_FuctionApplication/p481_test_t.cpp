// Q. 문자열 입력
// 1. 문자를 입력 받아서 그 중 문자가 아닌 숫자 등이 포함 되어 있으며 경고를 출력하는 코드 작성
// 2. 알파벳이 아닌 것이 있으면 제거하고 새로운 문자열로 만들어서 출력하는 코드 작성

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define ARRSIZE 128

int main()
{
	// 1번 문제
	char inputChar[ARRSIZE];
	printf("문자 입력 : ");
	scanf_s("%s", &inputChar, ARRSIZE);
	
	for (int i = 0; i < strlen(inputChar); i++)
	{
		if (isdigit(inputChar[i]))
		{
			puts("Error!");
			// return 0;
		}
	}
	printf("입력값 : %s\n", inputChar);
	
	// 2번 문제
	int i = 0;
	int j = 0;
	while (inputChar[i]!='\0')
	{
		if (isdigit(inputChar[i]) || !isalpha(inputChar[i]))
		{
			for (j = i; j < strlen(inputChar); j++)
			{
				inputChar[j] = inputChar[j + 1];
			}
			i--;	// 움직인 값이 숫자일 수 있음
		}
		i++;
	}

	printf("수정값 : %s\n", inputChar);

	return 0;
}