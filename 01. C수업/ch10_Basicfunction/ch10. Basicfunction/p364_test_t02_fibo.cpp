// Q. A�� �����̸� �� �� Ű��� �ִ�. �� �����̴� �� ���� ������ ���� �����̸� �����ϴ�.
// ���� �¾ ��� ���� �� ���� ������ ������ �����ϴ�. �����̰� � �������� �� ������ ����, ���� �����̰� � �����̰� �Ƿ��� 1���� ������ �մϴ�.
// �����̰� �¾�� 1�⸸�� �������� ���ٰ� �����ϰ�, �����̰� �Ŵ� ������ ������ 1�� �� ��ü ������ ���� �󸶳� �����ϴ��� �Ŵ� �� �� �ִ�.
// 1�� : n����, 2�� : n����, .... �̷�������

#include<stdio.h>

void Fibo(int month);
int Fibo_2(int cnt);

int main()
{
	int inputMonth;
	puts("[������ �� ���ϱ�]");
	printf("N���� �� �Է� : ");
	scanf_s("%d", &inputMonth);

	puts("\n1st");
	Fibo(inputMonth);

	puts("\n\n2ed");
	for (int i = 0; i < inputMonth; i++)
	{
		printf("\n%2d���� �� ������ �� : %2d\n", i + 1, Fibo_2(i));
	}
	
	return 0;
}

void Fibo(int month)
{
	/*
	-------------------------------------------
	�Ǻ���ġ ���� for ver.
	1 1 2 3 5 8 13 21 34  .....
	===================================
	��°� : 1 1 2 3  5  8
	������ : 1 2 3 5  8 13
	���İ� : 2 3 5 8 13 21

	3���� ��� Ȯ��
	-------------------------------------------
	*/

	int nowSnail = 1;
	int snailCnt = 1;
	int nextSnail = 1;

	for (int i = 0; i < month; i++)
	{
		snailCnt = nowSnail;
		nowSnail = nextSnail;
		nextSnail = snailCnt + nowSnail;

		printf("\n%2d���� �� ������ �� : %2d\n", i + 1, snailCnt);
	}

	return;
}

int Fibo_2(int cnt)
{
	/*
	---------------------------
	�Ǻ���ġ ���� ����Լ� ver.
	=========================
	return ���� �����ϱ�!
	---------------------------
	*/

	if (cnt <= 1)
	{
		return 1;
	}
	else
	{
		return Fibo_2(cnt - 1) + Fibo_2(cnt - 2);
	}
}