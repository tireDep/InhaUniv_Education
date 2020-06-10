// 399p
#include<stdio.h>

int main()
{
	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", szBuffer == pszData);	// 주소비교 : 0
	printf("%d\n", "TestString" == pszData);	// 동일 문자열 : 1
	printf("%d\n", "DataString" == pszData);	// 다른 문자열 : 0

	return 0;
}