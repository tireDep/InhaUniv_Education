// 78p

#include<stdio.h>

int main()
{
	long long int lldData = 4294967295LL;
	// 부호가 있는 64bit 정수형 변수 선언 및 정의

	printf("%d\n", lldData);
	printf("%u\n", lldData);
	// 64bit 정보 32bit 형식 문자로 출력

	printf("%u\n", lldData + 1);
	printf("%u\n", lldData + 2);
	printf("%u\n", lldData + 3);
	// 32bit로 출력 => 제대로 된 결과 x

	printf("%lld\n", lldData + 1);
	printf("%lld\n", lldData + 2);
	printf("%lld\n", lldData + 3);
	// 64bit로 출력 => 제대로 된 결과 o

	return 0;
}