// Q : ���, 0, ���� ����
#include<stdio.h>

int main()
{
	int input = 0;
	puts("�����Է�");
	scanf_s("%d", &input);

	if (input > 0)
	{
		puts("���");
	}
		
	if (input < 0)
	{
		puts("����");
	}
		
	if (input == 0)
	{
		puts("0");
	}

	return 0;
}