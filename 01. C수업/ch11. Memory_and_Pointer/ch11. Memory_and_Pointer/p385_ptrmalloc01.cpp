// 385p + 387p
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int *pList = NULL;

	//pList = (int *)malloc(sizeof(int) * 3);
	//memset(pList, 0, sizeof(int) * 3);

	pList = (int*)calloc(sizeof(int) * 3, sizeof(int));	// 요소의 개수, 각 요소의 바이트 단위 크기

	*pList = 10;
	*(pList + 1) = 20;
	*(pList + 2) = 30;

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pList[i]);
	}

	printf("\n%d\n", sizeof(_msize(pList)));

	free(pList);	// 동적할당한 메모리 해제
	return 0;
}

/*
---------------------------------------------------------------------------------
malloc() : 메모리 할당
- 인자 : 메모리크기

free() : 메모리 해제
- 인자 : 동적할당 한 메모리 이름

memset() : 메모리 값 초기화
- 인자 : 초기화 대상 메모리 주소, 초깃값, 초기화 대상 메모리의 바이트 단위 크기

calloc() : 메모리 선언 및 0으로 초기화
- 인자 : 요소의 개수, 각 요소의 바이트 단위 크기

_msize() : 동적 할당된 메모리 크기 확인
- 인자 : 메모리 이름
---------------------------------------------------------------------------------
*/