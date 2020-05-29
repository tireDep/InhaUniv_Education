// 614p
// 상수정의 코드를 그대로 두거나 주석 처리하는 것만으로 유니코드 기반의 코드를 MBCS 기반의 코드로 변경 할 수 있도록 한 것
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