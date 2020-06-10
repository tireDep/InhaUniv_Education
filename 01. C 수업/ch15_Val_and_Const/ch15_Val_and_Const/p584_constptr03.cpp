// 584p
#include<stdio.h>

int main()
{
	int nData = 10;
	const int *pnData = &nData; // 포인터가 가리키는 대상 상수화
	int* const pnNewData = &nData;	// 포인터 변수 자체를 상수화

	// *pnData = 20;
	// pnNewData = NULL;

	return 0;
}

/*
함수 내부에서 대상 메모리에 쓰기를 시도할 일이 없다는 것이 확실하다면
매개변수를 상수형 포인터로 선언하는 것이 좋음
*/