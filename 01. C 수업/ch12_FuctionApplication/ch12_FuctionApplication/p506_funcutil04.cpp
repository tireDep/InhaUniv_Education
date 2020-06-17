// 506p
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	// srand((unsigned)time(NULL));	// 랜덤 값 출력
	srand(1);	// 동일 값 출력됨

	for (int i = 0; i < 10; i++)
	{
		printf("%6d\n", rand());
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%6d\n", rand()%10);
	}

	return 0;
}

/*
------------------------------------------------
[주의]
3☆ : 1	==> 1
2☆ : 2	==> 2, 3
1☆ : 7	==> 4 ~ 9

rand() % 10 => 0~9 나옴
단, 이경우는 n/10 이 아님!(n/100)
뽑은 숫자와 %값을 줄여야 1/10을 만들 수 있음!
------------------------------------------------
*/