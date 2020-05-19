// 392p

#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[12] = { "HelloWorld" };
	char szNewBuffer[12] = { 0 };

	memcpy(szNewBuffer, szBuffer, 4);
	puts(szNewBuffer);

	memcpy(szNewBuffer, szBuffer, 6);
	puts(szNewBuffer);

	memcpy(szNewBuffer, szBuffer, sizeof(szBuffer));
	puts(szNewBuffer);

	return 0;
}

/*
----------------------------------------------------------------
memcpy() : 메모리 복사
- 인자 : 저장할 메모리, 복사할 정보가 있는 메모리, 메모리의 크기
----------------------------------------------------------------
*/