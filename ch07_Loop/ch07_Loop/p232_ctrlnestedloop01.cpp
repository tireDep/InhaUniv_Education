// 232p
#include<stdio.h>

int main()
{
	/*
	// ���� ���
	int i = 0, j = 0;

	i = 2;
	while (i <= 9)
	{
		j = 1;
		while (j <= 9)
		{
			printf("%d * %d = %d\n", i, j, i*j);
			j++;
		}
		i++;
		putchar('\n');
	}
	*/

	// �������
	int i = 0, j = 0;
	i = 1;

	while (i <= 9)
	{
		j = 2;
		while (j <= 9)
		{
			printf("%d * %d = %d\t", j, i, j*i);
			j++;
		}
		i++;
		puts("");
	}

	return 0;

}