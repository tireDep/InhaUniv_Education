// Q : 양수, 0, 음수 구별
#include<stdio.h>

int main()
{
	int input = 0;
	puts("숫자입력");
	scanf_s("%d", &input);

	if (input > 0)
	{
		puts("양수");
	}
		
	if (input < 0)
	{
		puts("음수");
	}
		
	if (input == 0)
	{
		puts("0");
	}

	return 0;
}