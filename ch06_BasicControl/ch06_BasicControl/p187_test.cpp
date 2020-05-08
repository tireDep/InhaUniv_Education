// 187p
// Q : 버스 요금 계산 프로그램
#include<stdio.h>

int main()
{
	puts("버스 요금 계산");
	
	int busRate = 1000;
	int inputAge = 0;
	printf("나이입력 : ");
	scanf_s("%d", &inputAge);

	if (20 > inputAge)
	{
		busRate -= busRate*0.25;
	}

	// if(inputAge>=20 ? busRate = busRate : busRate = busRate -  busRate*0.25)

	printf("최종요금 : %d원\n", busRate);

	return 0;
}