// 246p
#include<stdio.h>

int main()
{
	int i = 0;

	for (i = 0; i < 10; ++i)
	{
		if (i > 4)
		{
			continue;
		}

		printf("%dth\n", i);
	}

	printf("END : i == %d\n", i);
	return 0;
}