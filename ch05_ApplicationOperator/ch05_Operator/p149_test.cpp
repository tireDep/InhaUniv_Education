// Q : 3 * 8 / 4 연산을 기호를 사용하지 않고 계산
#include<stdio.h>

int main()
{
	printf("3 * 8 / 4 연산을 기호를 사용하지 않고 계산하기\n");

	int result = (3 << 3) >> 2;
	printf("결과 : %d\n", result);
	
	return 0;
}