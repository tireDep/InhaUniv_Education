// 273p
#include<stdio.h>

int main()
{
	int aList[5] = { 30,40,10,50,20 };
	char szBuffer[6] = { 'H','e','l','l','o','\0' };
	char szData[8] = { "Hello" };

	char *pszBuffer = "Hello";

	puts(szBuffer);
	puts(szData);
	puts(pszBuffer);

	printf("%s\n", szBuffer);
	printf("%s\n", pszBuffer);
	return 0;
}