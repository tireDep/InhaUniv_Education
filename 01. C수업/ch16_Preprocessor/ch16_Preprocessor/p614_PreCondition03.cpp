// 614p
// ������� �ڵ带 �״�� �ΰų� �ּ� ó���ϴ� �͸����� �����ڵ� ����� �ڵ带 MBCS ����� �ڵ�� ���� �� �� �ֵ��� �� ��
#include<stdio.h>

#define MYUNICODE

#ifdef MYUNICODE
	typedef wchar_t TCHAR;
	#define _T(string) L##string
	#define PRINT wprintf
#else
	typedef char TCHAR;
	#define _T(string) string
	#define PRINT printf
#endif // MYUNICODE


void main()
{
	TCHAR szData[16] = _T("Test string");
	PRINT(_T("%s\n"), szData);
	PRINT(_T("%d, %d\n"), sizeof(TCHAR),sizeof(szData));
}