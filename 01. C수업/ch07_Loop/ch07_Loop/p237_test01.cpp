// Q. ����ڿ��Լ� �� ���� ������ �Է¹޾� �� ������ �����ؼ� �� ���̿� �����ϴ� �������� ���� ���
#include<stdio.h>

int main()
{
	int temp = 0;
	int frontNum = 0, endNum = 0;
	printf("ù ��° �� �Է� : ");
	scanf_s("%d", &frontNum);

	printf("�� ��° �� �Է� : ");
	scanf_s("%d", &endNum);

	if (frontNum > endNum)	// ù ��°���� �� Ŭ ���
	{
		temp = frontNum;
		frontNum = endNum;
		endNum = temp;
	}

	int result = 0;
	for (int i = frontNum; i <= endNum; i++)
	{
		result += i;
	}

	/*
	int result = 0;
	if (frontNum > endNum)	// ù ��°���� �� Ŭ ���
	{
		for (int i = frontNum; i >= endNum; i--)
		{
			result += i;
		}
	}
	else
	{
		for (int i = frontNum; i <= endNum; i++)
		{
			result += i;
		}
	}
	*/
	/*
	-------------------------
	ȿ���� �鿡�� ���� x
	-------------------------
	*/

	printf("\n��� �� : %d\n", result);
	return 0;

}