// 487p
#include<stdio.h>
#include<string.h>

char *MyStrcat(char *pszDst, char *pszSrc);

int main()
{
	char szPath[128] = { 0 };
	char *pszEnd = NULL;

	// 대상 메모리에 문자열을 붙임
	pszEnd = MyStrcat(szPath, "C:\\Program Files\\");

	// 앞서 반환하는 주소를 첫 번째 인수로 호출해 문자열을 붙임
	pszEnd = MyStrcat(pszEnd, "CHS\\");
	pszEnd = MyStrcat(pszEnd, "C programming");

	puts(szPath);
	
	return 0;
}

char *MyStrcat(char *pszDst, char *pszSrc)
{
	while (*pszDst != '\0')	// 대상 메모리에 저장된 문자열의 끝을 찾음
	{
		++pszDst;
	}

	while (*pszSrc != '\0')	// 그 뒤에 새로운 문자열을 이어 붙임
	{
		*pszDst++ = *pszSrc++;
	}

	*++pszDst = '\0';	// 맨 끝을 NULL 문자로 마무리

	return --pszDst;	// 이어붙인 문자열의 마지막 글자가 저장된 메모리의 주소 반환
}