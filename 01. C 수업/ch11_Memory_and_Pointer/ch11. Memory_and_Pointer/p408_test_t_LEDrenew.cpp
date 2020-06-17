// Q. 키보드 입력 시, 새로운 문자열 입력을 받고 led 출력을 하게 함
// 조건
// - 포인터, 동적할당을 이용하여 문제 풀 것
// - 문자열 자동 스크롤 Sleep(), system("cls")
// - 키보드 키 입력시 새로운 문자열 입력받고 출력할 것


// ---------- [추후 할일] ---------- 
// 한글입력 가능하게 해보기
// --------------------------------

#include<stdio.h>
#include<string.h>
#include<conio.h>  
#include<Windows.h>
#include<malloc.h>

#include<stdlib.h>
#include <crtdbg.h>	// 메모리 누수

void InputLedString(char *inputString, char *printString);
void PrintLedString(char *printString);
void MemFree(void *mem);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);	// 메모리 누수

	char *inputString = (char *)malloc(sizeof(char) * 128);
	char *printString = (char *)malloc(sizeof(char) * 12);

	InputLedString(inputString, printString);
	
	MemFree(printString);
	MemFree(inputString);

	_CrtDumpMemoryLeaks();	// 메모리 누수

	return 0;
}

void InputLedString(char *inputString, char *printString)
{
	while (1)
	{
		printf("문자열 입력(Quit입력시 종료) : ");
		gets_s(inputString, _msize(inputString));

		if (_msize(printString) < strlen(inputString))
		{
			printString = (char*)realloc(printString, sizeof(char)*strlen(inputString) + 1);	// +1 : null 값 계산
			if (printString == NULL)
			{
				puts("ERROR!");
				return;
			}
			memset(printString, 0, _msize(printString));
			memcpy(printString, inputString, _msize(printString));
		}
		else
		{
			memcpy(printString, inputString, _msize(printString));
		}

		if (strcmp(printString, "Quit") == 0)	// 종료조건
		{
			break;
		}
		PrintLedString(printString);
	}
}

void PrintLedString(char *printString)
{
	int lenNum = strlen(printString);
	char tempString;
	
	system("cls");
	while (!_kbhit())
	{
		puts(printString);
		puts(printString);
		Sleep(1000);
		system("cls");

		for (int j = 0; j < lenNum - 1; j++)	// led 출력
		{
			if (j == 0)
			{
				tempString = printString[j];
			}
			printString[j] = printString[j + 1];
		}
		printString[lenNum - 1] = tempString;
	}
	_getch();	// 개행 제거용
}	// void PrintLedString()

void MemFree(void *mem)
{
	if (mem != NULL)
	{
		free(mem);
	}
	
	return;
}