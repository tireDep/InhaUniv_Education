// 495p
// #define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main()
{
	wchar_t *pwszData = L"String";
	wchar_t wszData[32];

	wcscpy_s(wszData, pwszData);
	wprintf_s(L"%s\n", wszData);
	// �����ڵ� ���ڿ� ���� �Լ�
	// �����ڵ�� ��������� ǥ���� �� ���ڿ� �տ� L�� �ٿ� L"String" �������� ǥ����

	return 0;
}