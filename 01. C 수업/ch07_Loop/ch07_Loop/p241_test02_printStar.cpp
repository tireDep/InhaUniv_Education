// Q. �Ƕ�̵� + ������ ���
#include<stdio.h>

int main()
{
	int input = 0;
	
	// �Ƕ�̵� ���
	puts("[�Ƕ�̵� ���]");
	printf("�� �� �Է� : ");
	scanf_s("%d", &input);

	int maxStar = 1 + 2 * (input - 1); 
	// �� ������ 1-3-5-7-9 ������ ������!
	int pCenter = maxStar / 2;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= maxStar; j++)
		{
			if (j >= pCenter - i && j <= pCenter + i)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		puts("");
	}

	input = 0;
	printf("\n");

	// ������ ���
	puts("[������ ���]");
	while (input % 2 == 0)
	{
		printf("�� �� �Է�(Ȧ��) : ");
		scanf_s("%d", &input);

		if (input % 2 == 0)
		{
			puts("\nȦ���� �Է��Ͻÿ�\n");
		}
	}

	int center = input / 2;
	int cnt = center - 1;
	
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (center >= i)	// �� ����
			{
				if (j >= center - i && j <= center + i)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}
			}
			else  // �Ʒ� ����
			{
				if (j >= center - cnt && j <= center + cnt)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}

				if (j == input -1)
				{
					cnt--;
				}
			}
		}
		puts("");
	}

	return 0;
}