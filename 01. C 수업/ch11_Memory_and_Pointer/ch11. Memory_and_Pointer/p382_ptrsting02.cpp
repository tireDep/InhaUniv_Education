// 382p
#include<stdio.h>

int main()
{
	char szBuffer[16] = { "Hello" };
	char *pszData = szBuffer;

	while (*pszData != '\0')
	{
		pszData++;
	}

	printf("Length : %d\n", pszData - szBuffer);
	return 0;
}