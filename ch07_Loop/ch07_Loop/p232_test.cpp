// Q. ����ڷκ��� ���� ���� �ϳ� �Է¹���, �� �� ��ŭ 3�� ����� ����ϴ� ���α׷� �ۼ�
#include<stdio.h>

int main()
{
	int input = 0;

	printf("���� ���� �Է� : ");
	scanf_s("%d", &input);

	if (input < 1)
	{
		puts("���� ������ �ƴϹǷ� 1�� ����");
		input = 1;
	}

	int num = 1;
	while (num <= input)
	{
		printf("%d ", num*3);
		num++;
	}
	puts("");

	return 0;
}