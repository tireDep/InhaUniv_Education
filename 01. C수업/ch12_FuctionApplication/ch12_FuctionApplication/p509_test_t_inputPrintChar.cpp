// Q. ����ڷκ��� �ִ� 10���� �ܾ �Է¹޾� �����ϴ� ���α׷��� �ۼ��϶�
// ������ ������ ���� �ܾ �տ� �;��Ѵ�.
// ��, ������ �ܾ�� 15���ڸ� ���� �ʴ´ٰ� �����Ѵ�.
// ���� 
// - ����� enterŰ �Է�
// - �Է��� �ҹ��ڷθ�

// �ϼ� �� ������ �ܾ���� ������ �ܾ� ���� ���� �����ؼ� Ǯ� ��
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void Method_1();

int main()
{
	Method_1();

	return 0;
}

void Method_1()
{
	int cnt = 0;
	int inputNum;
	printf("�Է��� �ܾ� �� �Է� : ");
	scanf_s("%d", &inputNum);
	char **inputChar = (char**)malloc(sizeof(char*) * inputNum);

	int inputMax;
	printf("�ܾ��� �ִ� ���� �Է� : ");
	scanf_s("%d", &inputMax);
	char *temp = (char *)malloc(sizeof(char)*inputMax);

	while (cnt < inputNum)
	{
		inputChar[cnt] = (char *)malloc(sizeof(char)*inputNum);
		rewind(stdin);
		printf("�ܾ �Է��ϼ��� : ");
		gets_s(inputChar[cnt], inputMax);
		if (strcmp(inputChar[cnt], "")==0)
		{
			break;
		}

		for (int i = 0; i < strlen(inputChar[cnt]); i++)
		{
			inputChar[cnt][i] = tolower(inputChar[cnt][i]);
		}
		cnt++;
	}

	int index;
	for (int i = 0; i < inputNum - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < inputNum; j++)
		{
			if (strcmp(inputChar[index], inputChar[j])>0)
			{
				index = j;
			}
		}
		strcpy_s(temp, strlen(inputChar[i]), inputChar[i]);
		strcpy_s(inputChar[i], strlen(inputChar[index]), inputChar[index]);
		strcpy_s(inputChar[index], strlen(inputChar[i]), temp);
	}

	puts("���");
	for (int i = 0; i < inputNum; i++)
	{
		if (strcmp(inputChar[i], " ") == 1)
		{
			printf("%s\n", inputChar[i]);
		}
	}

	if (temp != NULL)
	{
		free(temp);
	}

	if (inputChar != NULL)
	{
		for (int i = 0; i < inputNum; i++)
		{
			free(inputChar[i]);
		}
		free(inputChar);
	}
}