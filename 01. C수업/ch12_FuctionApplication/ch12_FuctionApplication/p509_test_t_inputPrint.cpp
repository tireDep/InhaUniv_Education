// Q. ����ڷκ��� �ܾ� �ϳ��� �Է¹��� ��, �� ���ڿ� ���� A���� Z���� ���ĺ��� ���� �� ���� �����ϴ��� ���� ���
// ��ҹ��ڴ� ���� ó��, �������� �ʴ� ���ĺ��� ������� ����, ���ĺ� �̿��� ���ڴ� ����

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
	char *inputChar = (char *)malloc(sizeof(char) * 128);
	if (inputChar == NULL)
	{
		puts("ERROR!");
		exit(1);
	}

	printf("�ܾ� �Է� : ");
	gets_s(inputChar, _msize(inputChar));

	int cnt;
	int i = -1;
	while (inputChar[i] != '\0')
	{
		cnt = 1;
		i++;
		if (isalpha(inputChar[i]))
		{
			for (int j = i+1; j < strlen(inputChar); j++)
			{
				if (toupper(inputChar[i]) == toupper(inputChar[j]))
				{
					cnt++;
					inputChar[j] = ' ';
				}
			}
		}
		else
		{
			continue;
		}
		printf("%c : %d\n", inputChar[i], cnt);
		inputChar[i] = ' ';
	}
	
	if (inputChar != NULL)
	{
		free(inputChar);
	}

	return 0;
}