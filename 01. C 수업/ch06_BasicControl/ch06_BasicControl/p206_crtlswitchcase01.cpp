// 206p
#include<stdio.h>

int main()
{
	char cOperator = 0;
	int x = 0, y = 0, nResult = 0;

	printf("숫자 및 기호 입력 : ");
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
		puts("ERROR : 알 수 없는 산술 연산입니다.");
		break;
	}

	printf("Result : %d\n", nResult);
	return 0;
}