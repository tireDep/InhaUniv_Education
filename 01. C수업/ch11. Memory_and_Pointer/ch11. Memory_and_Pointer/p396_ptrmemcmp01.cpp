// 396p
#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", memcmp(szBuffer, pszData, 10));	// ���� ���� : 0
	printf("%d\n", memcmp("teststring", pszData, 10));	// ������ ŭ : 1
	printf("%d\n", memcmp("DataString", pszData, 10));	// �������� ŭ : -1

	return 0;
}

/*
--------------------------------------------------------------------------
memcmp() : �޸� ��
-1 : ���� ���ڿ��� �� ŭ
0 : �� ���� ������
1 : ���� ���ڿ��� �� ŭ

��, ���� ������ ������ �� unsigned char������ ó��, ���� -1�� 255�� ó��
--------------------------------------------------------------------------
*/