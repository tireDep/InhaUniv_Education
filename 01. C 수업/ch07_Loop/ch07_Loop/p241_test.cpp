// Q. ���� �ﰢ�� ���
// ������, ������(�¿����)
#include<stdio.h>

int main()
{
	int input;

	// ������
	printf("���� �Է� : ");
	scanf_s("%d", &input);
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("* ");
		}
		puts("");
	}

	// ������(�¿����)
	printf("\n���� �Է� : ");
	scanf_s("%d", &input);
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= input; j++)
		{
			if (j >= input - i)
			{
				printf(" *");
			}
			else
			{
				printf("  ");
			}
		}
		puts("");
	}
}