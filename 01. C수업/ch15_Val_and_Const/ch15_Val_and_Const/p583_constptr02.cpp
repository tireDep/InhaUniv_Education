// 583p
#include<stdio.h>

void PrintString(const char *pszParam)
{
	// 매개변수가 상수형 포인터
	// 함수에서 포인터가 가리키는 대상 메모리에 쓰기르 시도할 수 x
	puts(pszParam);
}

void main()
{
	char szBuffer[32] = { "I am a boy." };

	// PrintString() 함수를 호출하더라도 szBuffer가 변경될 가능성은 x
	PrintString(szBuffer);
	PrintString("You are a girl.");

	return;
}