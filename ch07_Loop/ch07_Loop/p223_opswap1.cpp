// 223p
#include<stdio.h>

int main()
{
	char ch = 0;

	while ((ch = getchar()) != '\n') // \n 만나기 전까지 계속 입력을 받음
	{
		putchar(ch);
	}

	return 0;
}