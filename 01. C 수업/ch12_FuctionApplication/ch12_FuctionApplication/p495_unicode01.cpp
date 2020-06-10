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
	// 유니코드 문자열 전용 함수
	// 유니코드는 상수형으로 표기할 때 문자열 앞에 L을 붙여 L"String" 형식으로 표기함

	return 0;
}