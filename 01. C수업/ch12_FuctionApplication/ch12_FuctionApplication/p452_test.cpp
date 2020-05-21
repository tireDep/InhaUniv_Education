// 452p
// Q. 문자열을 복사하는 함수 만들기

#include<stdio.h>
#include<string.h>

void MyStrcpy(char *szBufferDst, int num, char *szBufferSrc);

int main()
{
	char szBufferSrc[12] = { "TestString" };
	char szBufferDst[12] = { 0 };
	
	MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);

	puts(szBufferDst);
	return 0;
}

void MyStrcpy(char *dstB, int maxSize, char *srcB)
{
	// memcpy(dstB, srcB, maxSize);

	for (int i = 0; i < maxSize; i++)
	{
		dstB[i] = srcB[i];
	}

	return;
}