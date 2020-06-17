// 509p
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	char ch;
	printf("Do you want to EXIT? (Y/N)");
	ch = _getch();

	if (ch == 'y' || ch == 'Y')
	{
		puts(" EXIT\n");
		exit(1);
	}

	puts("\nEnd of main()");

	return 0;
}