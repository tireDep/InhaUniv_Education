// 123p
#include<stdio.h>

int main()
{
	int x = 10, y = 20, nTmp = 0;

	printf("Before : x >> %d, y >> %d\n", x, y);
	
	nTmp = x;
	x = y;
	y = nTmp;

	printf("After  : x >> %d, y >> %d\n", x, y);
	
	return 0;
}