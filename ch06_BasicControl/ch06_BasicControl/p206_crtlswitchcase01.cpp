// 206p
#include<stdio.h>

int main()
{
	char cOperator = 0;
	int x = 0, y = 0, nResult = 0;

	printf("���� �� ��ȣ �Է� : ");
	scanf_s("%d%d", &x, &y);
	rewind(stdin);
	scanf_s("%c", &cOperator);

	switch (cOperator)
	{
	case '+':
		nResult = x + y;
		break;
	case '-':
		nResult = x - y;
		break;
	case '*':
		nResult = x * y;
		break;
	case '/':
		nResult = x / y;
		break;
	default:
		puts("ERROR : �� �� ���� ��� �����Դϴ�.");
		break;
	}

	printf("Result : %d\n", nResult);
	return 0;
}