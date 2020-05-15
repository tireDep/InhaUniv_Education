// 351p
#include<stdio.h>

int g_nCounter = 0;

void InitCounter(int nData); 
void IncreaseCounter();

int main()
{
	InitCounter(10);
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);

	return 0;
}

void InitCounter(int nData)
{
	g_nCounter = nData;
}

void IncreaseCounter()
{
	g_nCounter++;
}

/*
--------------------------------------------------
전역변수와 지역변수의 이름이 같을 경우
-> 지역변수 우선, 전역변수 사용할 경우 ::전역변수
--------------------------------------------------
*/