// Q : �� ���� ������ �Է¹޾Ƽ� �� ���� ���� ����ϴ� ���α׷� �ۼ�
// ��, ������ ū ������ ���� ���� �� ����� ��� => ����� ������ 0 �̻�
#include<stdio.h>

int main()
{
	int inputNum1, inputNum2;
	puts("�� ���� ���� �Է�");
	scanf_s("%d %d", &inputNum1, &inputNum2);
	// scanf_s("%d", &inputNum2);

	if (inputNum1 > inputNum2)
	{
		printf("��� : %d\n", inputNum1 - inputNum2);
	}
	else
	{
		printf("��� : %d\n", inputNum2 - inputNum1);
	}

	return 0;
}