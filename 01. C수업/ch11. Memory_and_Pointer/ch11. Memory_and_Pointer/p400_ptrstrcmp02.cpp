// 399p
#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", strcmp(szBuffer, pszData));
	printf("%d\n", strcmp("TestString", pszData));
	printf("%d\n", strcmp("Test", pszData));

	return 0;
}

/*
----------------------------------------------
strcmp() : �޸� ��(���ڿ� ���� ��)
-1 : ���� ���ڿ��� ���ĺ� ������ ����
0 : ���� ���ڿ�
1 : ���� ���ڿ��� ���ĺ� ������ ����
----------------------------------------------
*/