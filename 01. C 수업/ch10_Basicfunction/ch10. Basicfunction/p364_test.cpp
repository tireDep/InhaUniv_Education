// 364p
// Q. �⺻��ݰ� ���̸� �Ű������� �޾Ƽ� ���̿� ���� ��������� ����� ��ȯ�ϴ� GetFee() �ۼ�
// ���̿� ���� ���η�
// 0 ~ 3 : 100%
// 4 ~ 13 : 50%
// 14 ~ 19 : 75%
// 20 ~ : 0%

#include<stdio.h>

int GetFee(int cost, int age);
// static int staticNum = 0;
// const int constNum = 0;
int main()
{
	// static int staticNumIn = 0;

	int inputFee;
	int inputAge;
	int _cost;
	do
	{
		printf("�⺻��ݰ� ���̸� �Է��ϼ��� : ");
		scanf_s("%d %d", &inputFee, &inputAge);

	} while (-1 > inputAge || 0 >= inputFee);

	_cost = GetFee(inputFee, inputAge);

	printf("������� : %d\n", _cost);

	// printf("static : %d \nstaticIn : %d\n", ++staticNum, ++staticNumIn);
	return 0;
}

int GetFee(int cost, int age)
{
	float rate;
	if (20 <= age)
	{
		rate = 0;
	}
	else if (14 <= age && 19 >= age)
	{
		rate = 0.25;
	}
	else if (4 <= age && 13 >= age)
	{
		rate = 0.5;
	}
	else
	{
		rate = 1.0;
	}

	return cost - cost*rate;
}

/*
-----------------------------------------------------------------------------------------------------------------
���� ���� : ����, ����, static, const, register

-> ���� : ��� �ܺο� ����, ���α׷� ����� �� ����, extern���� �ܺ� �ҽ��ڵ忡�� ��� ����
-> ���� : ��� ���ο� ����, ����� ����� ����
-> static(����) : ���� �� �ʱ�ȭ + ���� �ʱ�ȭ �Ұ���, ���� ����, 
				 ��� ���ο��� ��������ó�� ��� ����(���α׷� ����� �� ����), �ܺ� ���+�ҽ��ڵ� ��� ��� x
-> const : ���� �� ����x, ���ó�� ��� ����
-> reguster : cpu���� �������� ����ǰ� �ӵ��� ���� ���, but ��� ���ϴ� ���� ����, ���� ������ or ���� �縸 ����
-----------------------------------------------------------------------------------------------------------------
*/