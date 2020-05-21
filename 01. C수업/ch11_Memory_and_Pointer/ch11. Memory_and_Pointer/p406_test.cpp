// 406p
// Q. 예제의 실행 코드 작성 및 출력결과에 대해 이유 기술
#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[32] = { "You are a girl." };
	char *pszData = szBuffer + 4;	// pszData 내용 : are a girl.

	printf("%c\n", szBuffer[0]);	// 출력값 : Y
	printf("%c\n", pszData[0]);	// 출력값 : a
	printf("%c\n", pszData[6]);	// 출력값 : g

	printf("%s\n", szBuffer + 4);	// 출력값 : are a girl.
	printf("%s\n", pszData);	// 출력값 : are a girl.
	printf("%s\n", pszData + 4);	// 출력값 : a girl.

	return 0;
}