// Q. ����ڰ� �Է��� ���ڸ�ŭ '*' ����ϱ�
// ������ ��� ��� 1, 9�� ����
#include<stdio.h>

int main()
{
	int input = 0;

	printf("1 ~ 9 ���� �Է� : ");
	scanf_s("%d", &input);

	if (1 > input)
	{
		input = 1;
	}
	else if (9 < input)
	{
		input = 9;
	}

	int cnt = 0;
	while (cnt < input)
	{
		cnt++;
		putchar('*');	// printf("*");
	}
	
	putchar('\n');	// puts("");
	return 0;

}