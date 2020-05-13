// Q. LED 문자열 출력
// HELLO -> ELLO H -> LLO HE -> LO HELL
#include<stdio.h>
#include<Windows.h>	// system("cls") 사용
#include<conio.h>	// _kbhit() 사용

int main()
{
	char _string[] = { "Hello " };	// 원본 문자열
	char printString[] = { "Hello " };	// 출력 문자열
	
	int checkNum = sizeof(_string) / sizeof(char) - 1;	// Null 제외한 범위
	int strPos = 0;

	for (int k = 0; k < checkNum + 1; k++)
	{
		if (!_kbhit())
		{
			puts(printString);
			Sleep(350);	// mSec 대기
			system("cls"); // 화면 삭제
		}
		else
		{
			puts("키보드 입력이 발생하여 종료");
			break;
		}

		/*
		원래 문제
		- 키보드 입력을 받을 때마다 화면 삭제 및 LED 이동 출력
			=> 무한루프 이용해야 함
		*/

		for (int i = 0; i < checkNum; i++)
		{
			/*
			-----------------------------------------------------------------------
			출력순서 : 01234/5 - 1234'0'/5 - 2340'1'/5 - 3401'2'/5 - 4012'3'/5 - 0123'4'/5
			-----------------------------------------------------------------------
			*/
			if (i + 1 >= checkNum)
			{
				printString[i] = _string[strPos];
				strPos++;
				// 맨 마지막 글자를 받아오기 위해 원본 문자열 이용
			}
			else
			{
				printString[i] = printString[i + 1];
				// 한 글자씩 앞으로 이동
			}
		}
	}

	puts("출력 종료");
	return 0;
}
/*
-----------------------------------------------------------------------
system("cls") : 화면 지우기  #include<Windows.h>
_kbhit() : 키보드 입력 확인  #include<conio.h>
Sleep(mSec) : mSec 대기
-----------------------------------------------------------------------
다른해결 방법
1. temp에 맨 앞글자 저장해 두기
2. 출력 위치 조정으로 풀기
ex) if(i==6) i=0; printf(array[i]);
-----------------------------------------------------------------------
*/