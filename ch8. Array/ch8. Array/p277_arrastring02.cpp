// 277p
#include<stdio.h>

int main()
{
	char szBuffer[32] = { 0 };
	int nLength = 0;

	printf("Input your name : ");
	gets_s(szBuffer);

	// szBuffer[5] = 'a';
	while (szBuffer[nLength] != '\0')
	{
		nLength++;
	}

	printf("Your name is %s(%d).\n", szBuffer, nLength);
	return 0;
}