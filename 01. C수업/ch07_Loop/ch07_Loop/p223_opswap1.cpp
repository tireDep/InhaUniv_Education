// 223p
#include<stdio.h>

int main()
{
	char ch = 0;

	while ((ch = getchar()) != '\n') // \n ������ ������ ��� �Է��� ����
	{
		putchar(ch);
	}

	return 0;
}