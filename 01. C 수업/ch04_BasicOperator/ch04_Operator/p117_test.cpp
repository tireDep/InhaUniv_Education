// 117p
// Q : 두 정수를 입력받아 평균을 계산해 출력하는 프로그램 + 사칙연산
#include<stdio.h>

int main()
{
	float num1, num2;
	printf("두 정수를 입력하세요 : ");
	scanf_s("%f %f", &num1, &num2);
	// scanf_s("%f%*c", &num1);
	// scanf_s("%f%*c", &num2);

	float result = 0;
	result = (num1 + num2) / 2;
	printf("AVG : %.2f\n", result);

	puts("\n------- 사칙연산 계산 -------");
	result = num1 + num2;
	printf(" + : %.2f\n", result);
	
	result = num1 - num2;
	printf(" - : %.2f\n", result);
	
	result = num1 * num2;
	printf(" * : %.2f\n", result);
	
	result = num1 / num2;
	printf(" / : %.2f\n", result);
}