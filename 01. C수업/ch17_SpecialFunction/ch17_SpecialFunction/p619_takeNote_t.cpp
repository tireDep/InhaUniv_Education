// 나중에 소스코드를 최적화할때 읽어보면 도움이 될 부분

// p633_함수 포인터

#include<stdio.h>
#include<stdlib.h>

int Add(int x, int y);
int Minus(int x, int y);
void PtrFuncEx();

// --------------------------------------------

// p634_역호출 구조

void RevCallEx();
int MyCompare(const void* pParam1, const void* pParam2);


// --------------------------------------------------------

// p637_정적 라이브러리

#include"Header.h"
#pragma comment(lib,"libTest_1")
// lib 로드

int main()
{
	PtrFuncEx();
	// --------------------
	RevCallEx();
	// --------------------
	PrintData(11);
	PrintString("asdfxcxcvasdfag");

	printf("Max : %d\n", GetMax(3, 10, 2, 100));
}

int Add(int x, int y)
{
	return x + y;
}

int Minus(int x, int y)
{
	return x - y;
}

void PtrFuncEx()
{
	int(*pF)(int, int);
	// 리턴값과 매개변수 인자형이 같은것만 가능
	pF = Add;
	printf("%d \n", pF(4, 5));

	pF = Minus;
	printf("%d \n", pF(4, 5));
}
// ------------------------------------------------

int MyCompare(const void* pParam1, const void* pParam2)
{
	return *(int*)pParam1 - *(int*)pParam2;	// 내림차순
	// 큰게 앞이면 양수, 작은게 앞이면 음수

	return -(*(int*)pParam1 - *(int*)pParam2);	// 오름차순
}

void RevCallEx()
{
	int aList[5] = { 30,10,40,50,20 };
	int i = 0;
	qsort(aList, 5, sizeof(int), MyCompare);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", aList[i]);
	}
	puts("");
}