// 404p
#include<stdio.h>
#include<string.h>

int main()
{
	char szBuffer[32] = { "You are a girl." };

	printf("%c\n", szBuffer[0]);	// ��°� : Y
	printf("%c\n", *szBuffer);	// ��°� : Y
	printf("%c\n", *(szBuffer + 0));	// ��°� : Y

	printf("%c\n", szBuffer[5]);	// ��°� : r
	printf("%c\n", *(szBuffer + 5));	// ��°� : r

	printf("%s\n", &szBuffer[4]);	// ��°� : are a girl.
	printf("%s\n", &*(szBuffer + 4));	// ��°� : are a girl.
	printf("%s\n", szBuffer + 4);	// ��°� : are a girl.
	// �ε��� 4 ��ġ���� ���ڿ� ���

	return 0;
}