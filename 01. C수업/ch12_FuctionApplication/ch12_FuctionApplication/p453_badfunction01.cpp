// 453p
// �߸��� �ڵ��� ����

#include<stdio.h>

int *TestFunc(void);

int main()
{
	int *pnResult = NULL;

	pnResult = TestFunc();

	printf("%d\n", *pnResult);	
	// �����Ͱ� ����Ű�� ��� �޸𸮴� ��ȿ���� ���� �޸�
	// but, ���ư���� �ϱ� ������ �����ؾ� ��!

	return 0;

}

int *TestFunc(void)
{
	int nData = 10;

	return &nData;
}