// Q. LED ���ڿ� ���
// HELLO -> ELLO H -> LLO HE -> LO HELL
#include<stdio.h>
#include<Windows.h>	// system("cls") ���
#include<conio.h>	// _kbhit() ���

int main()
{
	char _string[] = { "Hello " };	// ���� ���ڿ�
	char printString[] = { "Hello " };	// ��� ���ڿ�
	
	int checkNum = sizeof(_string) / sizeof(char) - 1;	// Null ������ ����
	int strPos = 0;

	for (int k = 0; k < checkNum + 1; k++)
	{
		if (!_kbhit())
		{
			puts(printString);
			Sleep(350);	// mSec ���
			system("cls"); // ȭ�� ����
		}
		else
		{
			puts("Ű���� �Է��� �߻��Ͽ� ����");
			break;
		}

		/*
		���� ����
		- Ű���� �Է��� ���� ������ ȭ�� ���� �� LED �̵� ���
			=> ���ѷ��� �̿��ؾ� ��
		*/

		for (int i = 0; i < checkNum; i++)
		{
			/*
			-----------------------------------------------------------------------
			��¼��� : 01234/5 - 1234'0'/5 - 2340'1'/5 - 3401'2'/5 - 4012'3'/5 - 0123'4'/5
			-----------------------------------------------------------------------
			*/
			if (i + 1 >= checkNum)
			{
				printString[i] = _string[strPos];
				strPos++;
				// �� ������ ���ڸ� �޾ƿ��� ���� ���� ���ڿ� �̿�
			}
			else
			{
				printString[i] = printString[i + 1];
				// �� ���ھ� ������ �̵�
			}
		}
	}

	puts("��� ����");
	return 0;
}
/*
-----------------------------------------------------------------------
system("cls") : ȭ�� �����  #include<Windows.h>
_kbhit() : Ű���� �Է� Ȯ��  #include<conio.h>
Sleep(mSec) : mSec ���
-----------------------------------------------------------------------
�ٸ��ذ� ���
1. temp�� �� �ձ��� ������ �α�
2. ��� ��ġ �������� Ǯ��
ex) if(i==6) i=0; printf(array[i]);
-----------------------------------------------------------------------
*/