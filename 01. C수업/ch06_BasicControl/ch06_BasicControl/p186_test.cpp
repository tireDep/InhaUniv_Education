// 186p
// Q : if���� �̿��� �ִ� ���ϱ�
#include<stdio.h>

int main()
{
	int input;
	scanf_s("%d", &input);
	
	int max = input;
	scanf_s("%d", &input);
	if (max < input)
	{
		max = input;
	}

	scanf_s("%d", &input);
	if (max < input)
	{
		max = input;
	}

	printf("MAX : %d\n", max);
	return 0;
}