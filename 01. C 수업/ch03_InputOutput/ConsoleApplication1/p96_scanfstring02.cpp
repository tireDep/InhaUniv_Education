// 96p
#include<stdio.h>

int main()
{
	char szBufferLeft[32] = { 0 };
	char szBufferRight[32] = { 0 };

	scanf_s("%s%s", szBufferLeft, szBufferRight);
	printf("%s %s\n", szBufferLeft, szBufferRight);


	return 0;
}