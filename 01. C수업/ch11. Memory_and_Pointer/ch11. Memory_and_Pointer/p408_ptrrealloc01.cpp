// 408p
#include<stdio.h>
#include<malloc.h>	// _msize()
#include<string.h>

int main()
{
	char *pszBuffer = NULL, *pszNewBuffer = NULL;

	pszBuffer = (char *)malloc(12);
	sprintf_s(pszBuffer, 12, "%s", "TestString");
	printf("[%p] %d %s\n", pszBuffer, _msize(pszBuffer), pszBuffer);

	pszNewBuffer = (char *)realloc(pszBuffer, 32);
	if (pszNewBuffer == NULL)
	{
		free(pszBuffer);
	}

	sprintf_s(pszNewBuffer, 32, "%s", "TestStringData");
	printf("[%p] %d %s\n", pszNewBuffer, _msize(pszNewBuffer), pszNewBuffer);
	free(pszNewBuffer);

	return 0;
}
/*
----------------------------------------------------------------------------------------------------------------
void realloc() : 이미 할당된 메모리를 재할당하는 함수
- 인자
-> void *memblock : 기존에 동적 할당된 메모리 주소, 만약 이 주소가 NULL이면 malloc()함수와 동일하게 동작
-> size_t size : 다시 할당받을 메모리의 바이트 단위 크기

int sprintf() : 문자열이 특정 주소의 메모리에 출력하는 함수
- 인자
-> char *buffer : 출력 문자열이 저장될 메모리 주소
-> const char *format : 형식 문자열이 저장된 메모리 주소
-> [, argument] : 형식 문자열에 대응하는 가변 인자들

- vs2015 보안강화ver 인자
-> char *buffer : 출력 문자열이 저장될 메모리 주소
-> size_t_BufferCount : 출력 문자열의 메모리 크기
-> const char *format : 형식 문자열이 저장된 메모리 주소
-> [, argument] : 형식 문자열에 대응하는 가변 인자들

- 반환값
-> 출력된 문자열의 개수

----------------------------------------------------------------------------------------------------------------

sprintf()의 경우, 최적화의 방법으로도 사용됨
=> 문자열을 계속 교체하는 방법
=> 단, 시간이 많이 걸릴 수 있기 때문에 상황에 맞게 사용해야함

==> 시간을 단축하는 방법은 변수에 해당 내용을 저장한 후 그때그때 출력하는 방법 (시간은 단축, 메모리공간은 증가)
----------------------------------------------------------------------------------------------------------------
*/