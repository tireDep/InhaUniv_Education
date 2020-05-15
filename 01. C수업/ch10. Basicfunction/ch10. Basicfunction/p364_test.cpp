// 364p
// Q. 기본요금과 나이를 매개변수로 받아서 나이에 따른 최종요금을 계산해 반환하는 GetFee() 작성
// 나이에 따른 할인률
// 0 ~ 3 : 100%
// 4 ~ 13 : 50%
// 14 ~ 19 : 75%
// 20 ~ : 0%

#include<stdio.h>

int GetFee(int cost, int age);
// static int staticNum = 0;
// const int constNum = 0;
int main()
{
	// static int staticNumIn = 0;

	int inputFee;
	int inputAge;
	int _cost;
	do
	{
		printf("기본요금과 나이를 입력하세요 : ");
		scanf_s("%d %d", &inputFee, &inputAge);

	} while (-1 > inputAge || 0 >= inputFee);

	_cost = GetFee(inputFee, inputAge);

	printf("최종요금 : %d\n", _cost);

	// printf("static : %d \nstaticIn : %d\n", ++staticNum, ++staticNumIn);
	return 0;
}

int GetFee(int cost, int age)
{
	float rate;
	if (20 <= age)
	{
		rate = 0;
	}
	else if (14 <= age && 19 >= age)
	{
		rate = 0.25;
	}
	else if (4 <= age && 13 >= age)
	{
		rate = 0.5;
	}
	else
	{
		rate = 1.0;
	}

	return cost - cost*rate;
}

/*
-----------------------------------------------------------------------------------------------------------------
변수 종류 : 전역, 지역, static, const, register

-> 전역 : 블록 외부에 선언, 프로그램 종료될 때 해제, extern으로 외부 소스코드에서 사용 가능
-> 지역 : 블록 내부에 선언, 블록을 벗어나면 해제
-> static(정적) : 선언 후 초기화 + 이후 초기화 불가능, 변경 가능, 
				 블록 내부에서 전역변수처럼 사용 가능(프로그램 종료될 때 해제), 외부 블록+소스코드 등에서 사용 x
-> const : 선언 후 변경x, 상수처럼 사용 가능
-> reguster : cpu일정 공간내에 선언되고 속도를 위해 사용, but 사용 안하는 것이 좋음, 작은 데이터 or 적은 양만 선언
-----------------------------------------------------------------------------------------------------------------
*/