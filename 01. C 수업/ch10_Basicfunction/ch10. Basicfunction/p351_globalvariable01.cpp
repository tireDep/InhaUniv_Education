// 351p
#include<stdio.h>

int g_nCounter = 0;

void InitCounter(int nData); 
void IncreaseCounter();

int main()
{
	InitCounter(10);
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);

	return 0;
}

void InitCounter(int nData)
{
	g_nCounter = nData;
}

void IncreaseCounter()
{
	g_nCounter++;
}

/*
--------------------------------------------------
���������� ���������� �̸��� ���� ���
-> �������� �켱, �������� ����� ��� ::��������
--------------------------------------------------
*/