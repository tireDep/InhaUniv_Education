// Q. ���ڿ� �Է�
// 1. ���ڸ� �Է� �޾Ƽ� �� �� ���ڰ� �ƴ� ���� ���� ���� �Ǿ� ������ ��� ����ϴ� �ڵ� �ۼ�
// 2. ���ĺ��� �ƴ� ���� ������ �����ϰ� ���ο� ���ڿ��� ���� ����ϴ� �ڵ� �ۼ�

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define ARRSIZE 128

int main()
{
	// 1�� ����
	char inputChar[ARRSIZE];
	printf("���� �Է� : ");
	scanf_s("%s", &inputChar, ARRSIZE);
	
	for (int i = 0; i < strlen(inputChar); i++)
	{
		if (isdigit(inputChar[i]))
		{
			puts("Error!");
			// return 0;
		}
	}
	printf("�Է°� : %s\n", inputChar);
	
	// 2�� ����
	int i = 0;
	int j = 0;
	while (inputChar[i]!='\0')
	{
		if (isdigit(inputChar[i]) || !isalpha(inputChar[i]))
		{
			for (j = i; j < strlen(inputChar); j++)
			{
				inputChar[j] = inputChar[j + 1];
			}
			i--;	// ������ ���� ������ �� ����
		}
		i++;
	}

	printf("������ : %s\n", inputChar);

	return 0;
}