// 450p

#include<stdio.h>

int GetLength(const char *pszParam)
{
	int nLength = 0;
	// pszParam = 1;
	while (pszParam[nLength] != '\0')
		nLength++;

	return nLength;
}

int main()
{
	char *pszData = "Hello";

	printf("%d\n", GetLength("Hi"));
	printf("%d\n", GetLength(pszData));
	return 0;
}