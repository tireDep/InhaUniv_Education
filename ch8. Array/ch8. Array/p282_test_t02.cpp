// Q. [9][9]�迭 ����, ������ ������ ������� �迭�� ������ ��,
// ����ڷκ��� �Է��� �޾� �ش� �ܸ� ���
#include<stdio.h>

int main()
{
	int calcArray[9][9] = { 0 };

	for (int i = 0; i < 9; i++)
	{
		if (i < 2)
		{
			continue;
		}

		for (int j = 0; j < 9; j++)
		{
			calcArray[i][j] = i * (j + 1);
		}
	}
	for (int k = 0; k < 9; k++)
	{
		calcArray[9][k] = 9 * (k + 1);
	}
	// ������ ���
	
	int input=100;
	int check = -1;
	while(1)
	{
		printf("����� �� : ");
		scanf_s("%d", &input);

		printf("[%d��]\n", input);
		for (int i = 0; i < 9; i++)
		{
			printf("%d * %d = %2d\n", input, i + 1, calcArray[input][i]);
		}
		puts("");

		scanf_s("%d", &check);
		if (check == 0)
		{
			break;
		}
	}

	puts("������ ����");

	return 0;
}