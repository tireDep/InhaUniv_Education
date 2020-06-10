// 164p
#include<stdio.h>

int main()
{
	int nInput = 0, nSelect = 0;

	scanf_s("%d", &nInput);

	nInput <= 10 ? nSelect = 10 : nSelect = 20;
	printf("%d\n", nSelect);

	nInput <= 10 ? (nSelect = 10) : (nSelect = 20);
	printf("%d\n", nSelect);

	return 0;
}

// c++에선 작동, c에선 작동 x