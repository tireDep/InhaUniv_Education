// Q. ¦���� ���
#include<stdio.h>

int main()
{
	int input;
	printf("���� �Է� : ");
	scanf_s("%d", &input);

	int cnt = 0;
	while (cnt < input)
	{
		cnt++;
		if (cnt == 0)
		{
			continue;
		}
		else if (cnt % 2 == 0)
		{
			printf("%d\n", cnt);
		}
		else
		{
			continue;
		}
	}

	return 0;
}