#include<stdio.h>

int GetData()
{
	int inputNum;
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &inputNum);

	return inputNum;
}

int GetMax(int num1, int num2, int num3)
{
	int maxNum = num1;

	maxNum = maxNum < num2 ? num2 : maxNum;
	maxNum = maxNum < num3 ? num3 : maxNum;

	return maxNum;
}

void printData(int num1, int num2, int num3, int maxNum)
{
	printf("%d, %d, %d �� ���� ū ���� %d �Դϴ�.\n", num1, num2, num3, maxNum);
	return;
}