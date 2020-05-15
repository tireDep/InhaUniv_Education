// Q. A는 달팽이를 한 쌍 키우고 있다. 이 달팽이는 한 달이 지나면 새끼 달팽이를 낳습니다.
// 새로 태어난 토기 역시 한 달이 지나면 새끼를 낳습니다. 달팽이가 어른 달팽이일 때 새끼를 낳고, 새끼 달팽이가 어른 달팽이가 되려면 1달이 지나야 합니다.
// 달팽이가 태어난지 1년만에 죽을리는 없다고 가정하고, 달팽이가 매달 새끼를 낳으면 1년 후 전체 달팽이 수가 얼마나 증가하는지 매달 알 수 있다.
// 1달 : n마리, 2달 : n마리, .... 이런식으로

#include<stdio.h>

void Fibo(int month);
int Fibo_2(int cnt);

int main()
{
	int inputMonth;
	puts("[달팽이 수 구하기]");
	printf("N개월 수 입력 : ");
	scanf_s("%d", &inputMonth);

	puts("\n1st");
	Fibo(inputMonth);

	puts("\n\n2ed");
	for (int i = 0; i < inputMonth; i++)
	{
		printf("\n%2d개월 후 달팽이 수 : %2d\n", i + 1, Fibo_2(i));
	}
	
	return 0;
}

void Fibo(int month)
{
	/*
	-------------------------------------------
	피보나치 수열 for ver.
	1 1 2 3 5 8 13 21 34  .....
	===================================
	출력값 : 1 1 2 3  5  8
	이전값 : 1 2 3 5  8 13
	이후값 : 2 3 5 8 13 21

	3개씩 끊어서 확인
	-------------------------------------------
	*/

	int nowSnail = 1;
	int snailCnt = 1;
	int nextSnail = 1;

	for (int i = 0; i < month; i++)
	{
		snailCnt = nowSnail;
		nowSnail = nextSnail;
		nextSnail = snailCnt + nowSnail;

		printf("\n%2d개월 후 달팽이 수 : %2d\n", i + 1, snailCnt);
	}

	return;
}

int Fibo_2(int cnt)
{
	/*
	---------------------------
	피보나치 수열 재귀함수 ver.
	=========================
	return 값에 주의하기!
	---------------------------
	*/

	if (cnt <= 1)
	{
		return 1;
	}
	else
	{
		return Fibo_2(cnt - 1) + Fibo_2(cnt - 2);
	}
}