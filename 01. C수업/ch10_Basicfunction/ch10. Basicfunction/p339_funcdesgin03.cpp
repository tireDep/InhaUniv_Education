// 339p
#include<stdio.h>

int GetResult();
char GetGrade(int nScore);

int main()
{
	int nReulst = 0;

	nReulst = GetResult();
	printf("당신의 학점은 '%c'(%d)입니다.\n", GetGrade(nReulst), nReulst);

	return 0;
}

int GetResult()
{
	int nResult = 0;
	printf("성적(0~100)을 입력하세요 : ");
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