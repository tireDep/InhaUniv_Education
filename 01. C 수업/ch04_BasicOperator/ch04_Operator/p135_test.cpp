// Q. scanf() �̿� �Է¹ް� ����ϱ�
// no.1 xx \n no.2 xx \n no.3 ����(no�� ���� ������ ���)
#include<stdio.h>

int main()
{
	int no = 0;
	int inputNum1 = 0;
	int inputNum2 = 0;
	int inputNum3 = 0;

	printf("�����Է� : ");
	scanf_s("%d %d %d", &inputNum1, &inputNum2, &inputNum3);
	
	printf("no.%d \t %d\n", ++no, inputNum1);
	printf("no.%d \t %d\n", ++no, inputNum2);
	printf("no.%d \t %d\n", ++no, inputNum3);

	return 0;
}