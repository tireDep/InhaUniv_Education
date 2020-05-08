// 192p
#include<stdio.h>

int main()
{
	int nInput = 0, nSelect = 0;
	scanf_s("%d", &nInput);

	if (nInput <= 10)
	{
		if (nInput < 0)
		{
			nSelect = 0;
		}
		else
		{
			nSelect = 10;
		}
	}
	else
	{
		nSelect = 20;
	}

	printf("%d\n", nSelect);

	return 0;
}