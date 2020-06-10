// Q. 1~10까지 총합 구하기
// for, while 둘 다 이용
#include<stdio.h>

int main()
{
	int result = 0;
	puts("For 문 출력");
	for (int i = 0; i <= 10; i++)
	{
		result += i;
	}
	printf("%d\n", result);
	puts("");

	puts("While 문 출력");
	int cnt = 0;
	result = 0;
	while (cnt <= 10)
	{
		result += cnt;
		cnt++;
	}
	printf("%d\n", result);
	puts("");

	return 0;

}