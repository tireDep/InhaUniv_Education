// 395p
// Q. 중대한 두 가지 오류
// 실행결과에는 문제 x, 두가지 결함 존재

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char szBuffer[12] = { "HelloWorld" };
	char *pszData = NULL;

	pszData = (char*)malloc(sizeof(char) * 12);
	// pszData = szBuffer; // 원본
	// memset(pszData, 0, sizeof(char));	// 수정 부분
	memcpy(pszData, szBuffer, sizeof(szBuffer));	// 수정부분

	puts(pszData);
	free(pszData);	// 수정 부분

	return 0;
}

/*
----------------------------
메모리 해지에 주의!!
----------------------------
*/