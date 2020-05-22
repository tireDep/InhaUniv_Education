// 508p
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char szCommand[512] = { 0 };
	printf("Input Command : ");
	gets_s(szCommand,sizeof(szCommand));
	// notepad 입력시 메모장 실행됨

	system(szCommand);

	return 0;
}