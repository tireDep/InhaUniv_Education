// 477p 
#include<stdio.h>

void PutData(char *pszParam);

int main()
{
	PutData("TestData");
	puts("");
	
	return 0;
}

void PutData(char *pszParam)
{
	if (*pszParam == '\0')
		return;

	putchar(*pszParam);
	PutData(pszParam + 1);
}