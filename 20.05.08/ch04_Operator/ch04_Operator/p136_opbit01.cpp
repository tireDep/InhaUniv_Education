// 136p
#include<stdio.h>

int main()
{
	int nData = 20;	// 10100
	int num = 15;	// 01111

	printf("& : %d\n", nData&num);	// 4
	printf("| : %d\n", nData|num);	// 31
	printf("^ : %d\n", nData^num);	// 27
	printf("~ : %d\n", ~nData);		// -21 // ÀÌ°Å¾Æ´Ô
	printf(">> : %d\n", nData >> 2);	// 5
	printf("<< : %d\n", nData << 2);	// 80

	return 0;
}