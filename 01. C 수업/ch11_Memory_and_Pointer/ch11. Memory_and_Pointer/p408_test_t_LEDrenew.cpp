// Q. Ű���� �Է� ��, ���ο� ���ڿ� �Է��� �ް� led ����� �ϰ� ��
// ����
// - ������, �����Ҵ��� �̿��Ͽ� ���� Ǯ ��
// - ���ڿ� �ڵ� ��ũ�� Sleep(), system("cls")
// - Ű���� Ű �Է½� ���ο� ���ڿ� �Է¹ް� ����� ��


// ---------- [���� ����] ---------- 
// �ѱ��Է� �����ϰ� �غ���
// --------------------------------

#include<stdio.h>
#include<string.h>
#include<conio.h>  
#include<Windows.h>
#include<malloc.h>

#include<stdlib.h>
#include <crtdbg.h>	// �޸� ����

void InputLedString(char *inputString, char *printString);
void PrintLedString(char *printString);
void MemFree(void *mem);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);	// �޸� ����

	char *inputString = (char *)malloc(sizeof(char) * 128);
	char *printString = (char *)malloc(sizeof(char) * 12);

	InputLedString(inputString, printString);
	
	MemFree(printString);
	MemFree(inputString);

	_CrtDumpMemoryLeaks();	// �޸� ����

	return 0;
}

void InputLedString(char *inputString, char *printString)
{
	while (1)
	{
		printf("���ڿ� �Է�(Quit�Է½� ����) : ");
		gets_s(inputString, _msize(inputString));

		if (_msize(printString) < strlen(inputString))
		{
			printString = (char*)realloc(printString, sizeof(char)*strlen(inputString) + 1);	// +1 : null �� ���
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

		if (strcmp(printString, "Quit") == 0)	// ��������
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

		for (int j = 0; j < lenNum - 1; j++)	// led ���
		{
			if (j == 0)
			{
				tempString = printString[j];
			}
			printString[j] = printString[j + 1];
		}
		printString[lenNum - 1] = tempString;
	}
	_getch();	// ���� ���ſ�
}	// void PrintLedString()

void MemFree(void *mem)
{
	if (mem != NULL)
	{
		free(mem);
	}
	
	return;
}