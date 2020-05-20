// 404p
#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[32] = { "You are a girl." };

	printf("%c\n", szBuffer[0]);	// 출력값 : Y
	printf("%c\n", *szBuffer);	// 출력값 : Y
	printf("%c\n", *(szBuffer + 0));	// 출력값 : Y

	printf("%c\n", szBuffer[5]);	// 출력값 : r
	printf("%c\n", *(szBuffer + 5));	// 출력값 : r

	printf("%s\n", &szBuffer[4]);	// 출력값 : are a girl.
	printf("%s\n", &*(szBuffer + 4));	// 출력값 : are a girl.
	printf("%s\n", szBuffer + 4);	// 출력값 : are a girl.
	// 인덱스 4 위치부터 문자열 출력

	return 0;
}