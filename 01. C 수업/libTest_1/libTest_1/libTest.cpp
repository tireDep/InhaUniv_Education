#include<stdio.h>

#include<stdarg.h>

void PrintData(int nParam)
{
	printf("PrintData() : %d\n", nParam);
}

void PrintString(const char* pszParam)
{
	printf("PrintString() : %s\n", pszParam);
}

int GetMax(int nCount, ...)	// ��������
{
	int nMax = -9999;
	int nParam = 0;
	int i = 0;

	va_list pList = NULL; // �������� ����Ʈ
	
	va_start(pList, nCount);	// �������ڿ� ���� ������ ����

	for (int i = 0; i < nCount; i++)
	{
		nParam = va_arg(pList, int);
		if (nParam > nMax)
			nMax = nParam;
	}

	va_end(pList);	// �����ٰ� �˷���

	return nMax;
}