// 584p
#include<stdio.h>

int main()
{
	int nData = 10;
	const int *pnData = &nData; // �����Ͱ� ����Ű�� ��� ���ȭ
	int* const pnNewData = &nData;	// ������ ���� ��ü�� ���ȭ

	// *pnData = 20;
	// pnNewData = NULL;

	return 0;
}

/*
�Լ� ���ο��� ��� �޸𸮿� ���⸦ �õ��� ���� ���ٴ� ���� Ȯ���ϴٸ�
�Ű������� ����� �����ͷ� �����ϴ� ���� ����
*/