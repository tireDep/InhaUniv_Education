// 583p
#include<stdio.h>

void PrintString(const char *pszParam)
{
	// �Ű������� ����� ������
	// �Լ����� �����Ͱ� ����Ű�� ��� �޸𸮿� ���⸣ �õ��� �� x
	puts(pszParam);
}

void main()
{
	char szBuffer[32] = { "I am a boy." };

	// PrintString() �Լ��� ȣ���ϴ��� szBuffer�� ����� ���ɼ��� x
	PrintString(szBuffer);
	PrintString("You are a girl.");

	return;
}