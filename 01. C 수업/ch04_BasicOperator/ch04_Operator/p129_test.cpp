// 129p
// Q : 세 정수의 누적 및 출력
// 세 정수를 입력받아 총합 출력, 단, 변수 추가 x
#include<stdio.h>

int main()
{
	int nInput, nTotal;
	
	// ------- 코드 작성 구간 -------
	nInput = nTotal = 0;
	printf("Input Three Tumber\n");

	scanf_s("%d", &nInput);
	nTotal += nInput;

	scanf_s("%d", &nInput);
	nTotal += nInput;

	scanf_s("%d", &nInput);
	nTotal += nInput;
	puts("");

	// ------- 코드 작성 구간 -------

	printf("Total : %d\n", nTotal);
	
	return 0;
}