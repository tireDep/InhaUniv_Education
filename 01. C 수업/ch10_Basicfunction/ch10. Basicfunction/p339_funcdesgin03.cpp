// 339p
#include<stdio.h>

int GetResult();
char GetGrade(int nScore);

int main()
{
	int nReulst = 0;

	nReulst = GetResult();
	printf("����� ������ '%c'(%d)�Դϴ�.\n", GetGrade(nReulst), nReulst);

	return 0;
}

int GetResult()
{
	int nResult = 0;
	printf("����(0~100)�� �Է��ϼ��� : ");
	scanf_s("%d", &nResult);

	return nResult;
}

char GetGrade(int nScore)
{
	if (nScore >= 90)
	{
		return 'A';
	}
	else if (nScore >= 80)
	{
		return 'B';
	}
	else if (nScore >= 70)
	{
		return 'C';
	}
	else if (nScore >= 60)
	{
		return 'D';
	}

	return 'F';
}