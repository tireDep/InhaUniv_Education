// 492p
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[128] = { "nData = x + y;\nnResult = a * b" };
	char *pszSep = " *+=;\n";
	char *pszToken = NULL;

	pszToken = strtok(szBuffer, pszSep);
	while (pszToken != NULL)
	{
		puts(pszToken);
		pszToken = strtok(NULL, pszSep);
	}

	printf("\nszBuffer : %s\n", szBuffer);

	return 0;
}