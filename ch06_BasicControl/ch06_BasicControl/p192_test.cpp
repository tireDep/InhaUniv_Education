// Q : 두 개의 정수를 입력받아서 두 수의 차를 출력하는 프로그램 작성
// 단, 무조건 큰 수에서 작은 수를 뺀 결과를 출력 => 결과는 무조건 0 이상
#include<stdio.h>

int main()
{
	int inputNum1, inputNum2;
	puts("두 개의 정수 입력");
	scanf_s("%d %d", &inputNum1, &inputNum2);
	// scanf_s("%d", &inputNum2);

	if (inputNum1 > inputNum2)
	{
		printf("결과 : %d\n", inputNum1 - inputNum2);
	}
	else
	{
		printf("결과 : %d\n", inputNum2 - inputNum1);
	}

	return 0;
}