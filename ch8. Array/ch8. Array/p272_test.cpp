// Q. �迭���� �ִ� ���ϱ�
// ���� : ���ο� ���� ���� x, ��°���� ������ ���ƾ� ��
// ��� �� : 50 40 10 50 20 \n MAX : 50 
#include<stdio.h>

int main()
{
	int aList[5] = { 30,40,10,50,20 };
	int i = 0;

	// -------- �ڵ� �ۼ� �κ� ---------
	for (i = 0; i < 4; i++)
	{
		if (aList[0] < aList[i + 1])
		{
			aList[0] = aList[i + 1];
		}
	}
	// ------- �ڵ� ���� X �κ� --------

	for (i = 0; i < 5; i++)
	{
		printf("%d\t", aList[i]);
	}
	putchar('\n');

	printf("MAX : %d\n", aList[0]);
	return 0;

}