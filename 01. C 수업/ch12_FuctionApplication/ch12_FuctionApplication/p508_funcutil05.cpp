// 508p
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char szCommand[512] = { 0 };
	printf("Input Command : ");
	gets_s(szCommand,sizeof(szCommand));
	// notepad �Է½� �޸��� �����

	system(szCommand);

	return 0;
}