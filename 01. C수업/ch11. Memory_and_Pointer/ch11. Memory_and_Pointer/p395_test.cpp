// 395p
// Q. �ߴ��� �� ���� ����
// ���������� ���� x, �ΰ��� ���� ����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char szBuffer[12] = { "HelloWorld" };
	char *pszData = NULL;

	pszData = (char*)malloc(sizeof(char) * 12);
	// pszData = szBuffer; // ����
	// memset(pszData, 0, sizeof(char));	// ���� �κ�
	memcpy(pszData, szBuffer, sizeof(szBuffer));	// �����κ�

	puts(pszData);
	free(pszData);	// ���� �κ�

	return 0;
}

/*
----------------------------
�޸� ������ ����!!
----------------------------
*/