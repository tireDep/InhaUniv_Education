// 117p
#include<stdio.h>

int main()
{
	int x = 0;
	scanf_s("숫자 입력 : %d", &x);

	printf("몫 : %d\n", x / 3);
	printf("나머지 : %d\n", x % 3);

	return 0;
}
// 나머지 연산자는 실수 형태! => 실수 형태로 작업이 되어야함

/*
float y = 0;
scanf_s("숫자 입력 : %f", &y);
printf("몫 : %f\n", y / 3.0);
printf("나머지 : %f\n", y % 3.0);

실행되지 않음
*/