// 168p
// Q : ��ʸ�Ʈ ������� ���� ū �� ���ϱ� + �ּڰ�
#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0, num3 = 0;
	int maxNum = 0, minNum = 0;

	printf("�� ���� �Է� : ");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	maxNum = num1 > num2 ? num1 : num2;
	maxNum = maxNum > num3 ? maxNum : num3;
	printf("Max : %d\n", maxNum);
	
	minNum = num1 < num2 ? num1 : num2;
	minNum = minNum < num3 ? minNum : num3;
	printf("Min : %d\n", minNum);

	return 0;
}