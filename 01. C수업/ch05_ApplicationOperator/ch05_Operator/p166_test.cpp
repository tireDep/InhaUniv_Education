// Q : cm ���� Ű�� �Է¹޾� 150cm�̻� �հ�, �ƴϸ� ���հ� / ���� ������ ���
#include<stdio.h>

int main()
{
	int inputVal = 0;
	char result = 0;

	printf("Ű�� �Է��Ͻÿ� : ");
	scanf_s("%d", &inputVal);

	// inputVal >= 150 ? puts("��� : �հ�") : puts("��� : ���հ�");
	
	result = inputVal >= 150 ? 1 : 0;
	printf("��� : %s\n", result >= 1 ? "�հ�" : "���հ�");
	return 0;
}