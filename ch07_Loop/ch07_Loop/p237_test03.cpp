// Q. �����ܿ��� �� �ܸ� ����ϱ�
// �����ϱ�
#include<stdio.h>

int main()
{
	int input;
	printf("���� �Է� : ");
	scanf_s("%d", &input);
	
	if (2 > input || 9 < input)
	{
		puts("Error!");
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			if (i != 0)
			{
				printf("%d * %d = %2d\n", input, i, input*i); // %2d : ����
			}
		}
	}
	
	/*
	if (2 > input || 9 < input)
	{
		puts("Error!");
	}

	else
	{
		int cnt = 1;
		while (cnt < 10)
		{
			printf("%d * %d = %2d\n", input, cnt, input*cnt); // %2d : ����
			cnt++;
		}
	}
	*/

	return 0;
}