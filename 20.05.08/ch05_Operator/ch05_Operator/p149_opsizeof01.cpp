// 149p
#include<stdio.h>

int main()
{
	int nData = 10;

	printf("%d, %d, %d\n", sizeof(5), sizeof(nData), sizeof(int));
	printf("%d, %d\n", sizeof('a'), sizeof(char));
	printf("%d, %d\n", sizeof(123.45f), sizeof(123.45));

	printf("%d, %d\n", sizeof(nData+10), sizeof(++nData));
	printf("%d\n", nData);

	return 0;
}