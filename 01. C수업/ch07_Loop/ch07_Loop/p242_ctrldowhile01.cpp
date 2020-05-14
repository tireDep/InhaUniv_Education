// 242p
#include<stdio.h>

int main()
{
	char ch = 0;

	do 
	{
		ch = getchar();
		putchar(ch);
	} while (ch != '\n');

	return 0;
}