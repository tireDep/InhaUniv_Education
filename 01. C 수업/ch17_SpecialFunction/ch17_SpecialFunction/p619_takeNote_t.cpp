// ���߿� �ҽ��ڵ带 ����ȭ�Ҷ� �о�� ������ �� �κ�

// p633_�Լ� ������

#include<stdio.h>
#include<stdlib.h>

int Add(int x, int y);
int Minus(int x, int y);
void PtrFuncEx();

// --------------------------------------------

// p634_��ȣ�� ����

void RevCallEx();
int MyCompare(const void* pParam1, const void* pParam2);


// --------------------------------------------------------

// p637_���� ���̺귯��

#include"Header.h"
#pragma comment(lib,"libTest_1")
// lib �ε�

int main()
{
	PtrFuncEx();
	// --------------------
	RevCallEx();
	// --------------------
	PrintData(11);
	PrintString("asdfxcxcvasdfag");

	printf("Max : %d\n", GetMax(3, 10, 2, 100));
}

int Add(int x, int y)
{
	return x + y;
}

int Minus(int x, int y)
{
	return x - y;
}

void PtrFuncEx()
{
	int(*pF)(int, int);
	// ���ϰ��� �Ű����� �������� �����͸� ����
	pF = Add;
	printf("%d \n", pF(4, 5));

	pF = Minus;
	printf("%d \n", pF(4, 5));
}
// ------------------------------------------------

int MyCompare(const void* pParam1, const void* pParam2)
{
	return *(int*)pParam1 - *(int*)pParam2;	// ��������
	// ū�� ���̸� ���, ������ ���̸� ����

	return -(*(int*)pParam1 - *(int*)pParam2);	// ��������
}

void RevCallEx()
{
	int aList[5] = { 30,10,40,50,20 };
	int i = 0;
	qsort(aList, 5, sizeof(int), MyCompare);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", aList[i]);
	}
	puts("");
}