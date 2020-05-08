// 204P
// Q : 단계별 분류에 따른 버스요금 계산
// ~3 & 65~ : 0, 4~13 : 50%, 14~19 : 25%, 20~ : 0%
#include<stdio.h>

int main()
{
	int busRate = 1000;
	int inputAge = 0;
	printf("나이 입력 : ");
	scanf_s("%d", &inputAge);

	if (3 >= inputAge || 65 <= inputAge)
	{
		busRate = 0;
	}
	else
	{
		if (4 <= inputAge && 13 >= inputAge)
		{
			busRate -= busRate*0.5;
		}
		else if (14 <= inputAge && 19 >= inputAge)
		{
			busRate -= busRate*0.25;
		}
	}

	printf("최종요금 : %d원\n", busRate);
	return 0;

}