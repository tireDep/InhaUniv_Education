// 269p
#include<stdio.h>

#define MAX 5

int main()
{
	int aList[5] = { 10,20,30,40,50 };
	int aListNew[MAX] = { 0 };	//define�� �̿��ؼ� �迭 ���� ����
	int i = 0;

	// aListNew = aList; // �����߻�
	// �������� ���� �ǿ����ڰ� ������ �ƴ϶� �Ұ��� => �迭������ �ּһ��

	for (i = 0; i < 5; i++)
	{
		aListNew[i] = aList[i];
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d\n", aListNew[i]);
	}
	putchar('\n');

	return 0;
}

/*
----------------------------------------
���������� ���̴� ��
int : n + ~
float : f + ~
double : d + ~
array : a / arr / array + ~

��Ÿ 
-> _ + ~
-> ��ҹ��� ���
----------------------------------------
*/