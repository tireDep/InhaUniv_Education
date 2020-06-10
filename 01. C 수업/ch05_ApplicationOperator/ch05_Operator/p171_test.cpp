// 171p
// Q : 서바이벌 방식으로 가장 큰 수 구하기 - 오류수정
// 입력범위는 -100 ~ 100 사이로 입력, 5번행만 수정(변수 선언행)
#include<stdio.h>

int main()
{
	int nMax = -9999, nInput = 0;
	// int nMax, nInput = 0; 수정함
	
	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf_s("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	printf("Max : %d\n", nMax);
	
	return 0;
}