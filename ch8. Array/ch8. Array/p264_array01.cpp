// 264p
#include<stdio.h>

int main()
{
	int aList[5] = { 0 };
	int i = 0;
	// int k = 5;
	// int aList[k] = { 0 };
	// �̷� ���´� �Ұ���!

	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &aList[i]);
	}

	aList[0] = 100;
	aList[3] = 200;


	puts("");
	for (i = 0; i < 5; i++)
	{
		printf("%d\t %d\n", aList[i], &aList[i]);
	}

	printf("\n%d\t %d\n", aList[0], aList);
	return 0;

}
/*
----------------------------------
�迭������ ù ��° ����� �ּ���
----------------------------------
*/