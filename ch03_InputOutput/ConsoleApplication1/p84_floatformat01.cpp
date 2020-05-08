// 84p
#include<stdio.h>

int main()
{
	double dData = 123.456;

	printf("%f, %f\n", dData, -123.456);

	printf("%.1f\n", dData);
	printf("%.2f\n", dData);
	printf("%.3f\n", dData);
	// 반올림해서 .x 자리까지 출력

	printf("%8d\n", 123);

	printf("%12.3f\n", dData);
	// 소수점 포함 12자리 출력

	printf("%012.3f\n", dData);
	// 소수점 포함 12자리 출력, 빈자리는 0으로 채움

	return 0;
}