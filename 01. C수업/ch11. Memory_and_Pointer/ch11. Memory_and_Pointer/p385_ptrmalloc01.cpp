// 385p + 387p
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int *pList = NULL;

	//pList = (int *)malloc(sizeof(int) * 3);
	//memset(pList, 0, sizeof(int) * 3);

	pList = (int*)calloc(sizeof(int) * 3, sizeof(int));	// ����� ����, �� ����� ����Ʈ ���� ũ��

	*pList = 10;
	*(pList + 1) = 20;
	*(pList + 2) = 30;

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pList[i]);
	}

	printf("\n%d\n", sizeof(_msize(pList)));

	free(pList);	// �����Ҵ��� �޸� ����
	return 0;
}

/*
---------------------------------------------------------------------------------
malloc() : �޸� �Ҵ�
- ���� : �޸�ũ��

free() : �޸� ����
- ���� : �����Ҵ� �� �޸� �̸�

memset() : �޸� �� �ʱ�ȭ
- ���� : �ʱ�ȭ ��� �޸� �ּ�, �ʱ갪, �ʱ�ȭ ��� �޸��� ����Ʈ ���� ũ��

calloc() : �޸� ���� �� 0���� �ʱ�ȭ
- ���� : ����� ����, �� ����� ����Ʈ ���� ũ��

_msize() : ���� �Ҵ�� �޸� ũ�� Ȯ��
- ���� : �޸� �̸�
---------------------------------------------------------------------------------
*/