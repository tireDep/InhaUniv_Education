// 114p
#include<stdio.h>

int main()
{
	int x = 10;
	printf("%d\n", x * 10);
	
	printf("%d\n", x * 10.0);
	// 출력 불가
	
	printf("%d\n", x / 10);
	// 실수 형태 x, 소수점 이하 절삭

	printf("%d\n", 5 / 2);
	// 출력 불가

	printf("%f\n", 5 / 2);
	// 소수점 이하 절삭
	
	printf("%f\n", 5.0 / 2);

	return 0;
}

// 출력결과 : 100 0 1 2 0.000000 2.500000