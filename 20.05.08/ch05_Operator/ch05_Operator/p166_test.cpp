// Q : cm 단위 키를 입력받아 150cm이상 합격, 아니면 불합격 / 삼항 연산자 사용
#include<stdio.h>

int main()
{
	int inputVal = 0;
	char result = 0;

	printf("키를 입력하시오 : ");
	scanf_s("%d", &inputVal);

	// inputVal >= 150 ? puts("결과 : 합격") : puts("결과 : 불합격");
	
	result = inputVal >= 150 ? 1 : 0;
	printf("결과 : %s\n", result >= 1 ? "합격" : "불합격");
	return 0;
}