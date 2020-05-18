/*
Q. �ϻ��� �� ���ϱ�
���� ���� x�� �ϻ��� ���̷��� x�� �ڸ����� ������ x�� ���������� �մϴ�. 
���� ��� 18�� �ڸ��� ���� 1+8=9�̰�, 18�� 9�� ������ �������Ƿ� 18�� �ϻ��� ���Դϴ�. 
�ڿ��� x�� �Է¹޾� x�� �ϻ��� ������ �ƴ��� �˻��ϴ� �Լ�, solution�� �ϼ����ּ���.

���� ����
x�� 1 �̻�, 10000 ������ �����Դϴ�.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x);

int main()
{
	int inputNum;
	scanf_s("%d", &inputNum);

	solution(inputNum);

	return 0;
}


bool solution(int x)
{
	int check = 0;
	int temp = x;

	for (int i = 10000; i > 0; i = i / 10)
	{
		check = check + temp / i;
		temp = temp%i;
	}

	if (x % check == 0)
	{
		puts("�ϻ��� �� O");
		return true;
	}
	else
	{
		puts("�ϻ��� �� X");
		return false;
	}
}