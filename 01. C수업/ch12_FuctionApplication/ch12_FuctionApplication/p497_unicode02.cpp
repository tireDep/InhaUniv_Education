// 497p
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	wchar_t *pwszData = L"String";	// �����ڵ� ���ڿ� ����� �ʱ�ȭ

	char szData[32];
	size_t nConverted = 0;
	// MBCS ���ڿ��� ���� �� �ִ� �迭 

	nConverted = wcstombs(NULL, pwszData, 32);
	printf("%d\n", nConverted);
	// ��ȯ�� ���ڿ��� ���̸� �˾Ƴ�

	nConverted = wcstombs(szData, pwszData, 32);
	// �����ڵ� ���ڿ��� MBCS ���ڿ��� ������ szData ����

	printf("%s (%d)\n", szData, nConverted);
	// ��ȯ��� ���

	return 0;
}

/*
--------------------------------------------------
wcstombs() : �����ڵ� ���ڿ��� MBCS ���ڿ��� ��ȯ
mbstowcs() : MBCS ���ڿ��� �����ڵ�� ��ȯ
--------------------------------------------------
*/