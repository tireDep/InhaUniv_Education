// 155p
#include<stdio.h>

int main()
{
	int nInput = 0, bResult = 0;

	scanf_s("%d", &nInput);

	bResult = nInput < 4 || nInput >= 60;

	printf("Result : %d (1:True, 0:Fasle)\n", bResult);

	return 0;
}