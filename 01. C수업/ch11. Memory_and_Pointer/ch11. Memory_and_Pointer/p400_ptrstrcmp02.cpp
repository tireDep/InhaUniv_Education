// 399p
#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", strcmp(szBuffer, pszData));
	printf("%d\n", strcmp("TestString", pszData));
	printf("%d\n", strcmp("Test", pszData));

	return 0;
}

/*
----------------------------------------------
strcmp() : 메모리 비교(문자열 길이 비교)
-1 : 뒤의 문자열이 알파벳 순서상 나중
0 : 동일 문자열
1 : 앞의 문자열이 알파벳 순서상 나중
----------------------------------------------
*/