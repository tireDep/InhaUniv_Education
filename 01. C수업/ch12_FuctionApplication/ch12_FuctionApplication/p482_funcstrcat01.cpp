// 483p
#include<stdio.h>
#include<string.h>

int main()
{
	char szPath[128] = { "C::\\Program Files\\" };
	char szBuffer[128] = { 0 };

	printf("Input path : ");
	gets_s(szBuffer, sizeof(szBuffer));

	strcat_s(szPath, szBuffer);
	puts(szPath);

	return 0;
}