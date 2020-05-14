// Q. 사용자가 입력한 숫자만큼 '*' 출력하기
// 범위를 벗어날 경우 1, 9로 보정
#include<stdio.h>

int main()
{
	int input = 0;

	printf("1 ~ 9 사이 입력 : ");
	scanf_s("%d", &input);

	if (1 > input)
	{
		input = 1;
	}
	else if (9 < input)
	{
		input = 9;
	}

	int cnt = 0;
	while (cnt < input)
	{
		cnt++;
		putchar('*');	// printf("*");
	}
	
	putchar('\n');	// puts("");
	return 0;

}