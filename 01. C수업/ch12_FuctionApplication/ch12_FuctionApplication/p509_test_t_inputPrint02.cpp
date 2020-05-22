// // Q. ����ڷκ��� �ܾ� �ϳ��� �Է¹��� ��, �� ���ڿ� ���� A���� Z���� ���ĺ��� ���� �� ���� �����ϴ��� ���� ���
// ��ҹ��ڴ� ���� ó��, �������� �ʴ� ���ĺ��� ������� ����, ���ĺ� �̿��� ���ڴ� ����

// [�ٸ� ��� Ǯ��]

#include<stdio.h>
#include<string.h>

void Method_ASCII();
void Method_Token();

int main()
{
	Method_ASCII();	// �ƽ�Ű �ڵ� �̿�
	puts("----------------------------------------------------");

	Method_Token();	// ��ū ���
	puts("----------------------------------------------------");

	return 0;
}

void Method_ASCII()
{
	char *alpha = "abcdefghijklmnopqrstuvwxyz";
	char inputStr[128] = { 0 };

	printf("�Է� : ");
	gets_s(inputStr, sizeof(inputStr));
	// ���ڿ� �Է�

	int count[26] = { 0 };
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < strlen(inputStr); j++)
		{
			if (inputStr[j] == alpha[i] || inputStr[j] == alpha[i] - 32)
			{
				count[i]++;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c : %d\n", alpha[i], count[i]);
		}
	}
}

void Method_Token()
{
	char inputStr[128] = { 0 };
	char enG[27] = { 0 };

	for (int i = 0; i < 26; i++)
	{
		enG[i] = i + 97;
	}

	printf("�Է� : ");
	gets_s(inputStr, sizeof(inputStr));
	
	char *pszNewStart = inputStr;
	pszNewStart = strpbrk(pszNewStart, enG);

	int count[26] = { 0 };
	int i = 0;
	while (pszNewStart != NULL)	// ã�� ���� ��� NULL ��ȯ
	{
		count[*pszNewStart - 97]++;
		pszNewStart = strpbrk(pszNewStart + 1, enG);
	}

	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c : %d\n", enG[i], count[i]);
		}
	}
}