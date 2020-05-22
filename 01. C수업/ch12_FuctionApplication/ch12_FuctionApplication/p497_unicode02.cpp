// 497p
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	wchar_t *pwszData = L"String";	// 유니코드 문자열 상수로 초기화

	char szData[32];
	size_t nConverted = 0;
	// MBCS 문자열을 담을 수 있는 배열 

	nConverted = wcstombs(NULL, pwszData, 32);
	printf("%d\n", nConverted);
	// 변환된 문자열의 길이를 알아냄

	nConverted = wcstombs(szData, pwszData, 32);
	// 유니코드 문자열을 MBCS 문자열로 변경해 szData 저장

	printf("%s (%d)\n", szData, nConverted);
	// 변환결과 출력

	return 0;
}

/*
--------------------------------------------------
wcstombs() : 유니코드 문자열을 MBCS 문자열로 변환
mbstowcs() : MBCS 문자열을 유니코드로 변환
--------------------------------------------------
*/