// Q. 사용자로부터 계속해서 정수 입력 받고 더함, 
// 0을 입력할 때 까지 지속하며 0이 입력될 경우 정수의 합 출력 후 종료
#include<stdio.h>

int main()
{
	int input = 1;
	int result = 0;

	while (input != 0)
	{
		printf("값 입력(0입력 시 종료) : ");
		scanf_s("%d", &input);

		result += input;
	}

	printf("\n결과 : %d\n", result);
	return 0;

}