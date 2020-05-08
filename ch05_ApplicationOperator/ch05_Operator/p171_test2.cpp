// Q : 인간의 수명이 100년이라 가정, 담배 한개피를 피우면 수명이 2분 단축
//     어떤 사람이 성인(20살)이 된 이후 담배를 20년간 하루에 n개피 씩 피웠다면 
//     수명은 얼마나 단축되었고 몇 살까지 살 수 있을지 계산(기대수명)
#include<stdio.h>

int main()
{
	int inputNum = 0;

	printf("담배 개피 수 : ");
	scanf_s("%d", &inputNum);
	
	int lossTime = inputNum * 2 * 365 * 20; // 준 시간(분)
	// 개수 * 2분 * 1년 * 20년

	int loseyear = lossTime / 60 / 24 / 365;
	int losemonth = lossTime / 60 / 24 % 356 / 30;
	int loseday = lossTime / 60 / 24 % 365 % 30;
	int losehour = lossTime / 60 % 24;
	int losemin = lossTime % 60;

	// -------------------- 
	// 60 : 1시간
	// 24 : 1일 
	// 30 : 1달
	// 12 : 1년
	// --------------------

	printf("단축된 수명 : %d년 %d개월 %d일 %d시간 %d분 \n", loseyear, losemonth, loseday, losehour, losemin);
	
	int lifeTime = (24 * 60 * 365 * 100) - lossTime; // 남은 수명

	int lifeyear = lifeTime / 60 / 24 / 365;
	int lifemonth = lifeTime / 60 / 24 % 356 / 30;
	int lifeday = lifeTime / 60 / 24 % 365 % 30;
	int lifehour = lifeTime / 60 % 24;
	int lifemin = lifeTime % 60;

	printf("기대 수명 : %d년 %d개월 %d일 %d시간 %d분\n", lifeyear, lifemonth, lifeday, lifehour, lifemin);
	printf("            (약 %d세, 40살 기준 약 %d년 남음)\n", lifeyear, lifeyear - 40);

	return 0;

}