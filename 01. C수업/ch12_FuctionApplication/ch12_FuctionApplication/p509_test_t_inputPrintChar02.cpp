// Q. ����ڷκ��� �ִ� 10���� �ܾ �Է¹޾� �����ϴ� ���α׷��� �ۼ��϶�
//  ==> ������ �ܾ� �� �Է� �ް� ���� �� ��� �ϴ� ���α׷�

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void CheckMem(char *mem);
void CheckFree(char *mem);

void InputChar_Fun();
void SortChar(char **inputChar, char *temp, int cnt);
void PrintChar(char **inputChar, int cnt);

int main()
{
	InputChar_Fun();

	return 0;
}

void InputChar_Fun()
{
	int cnt = 0;
	int inputCnt;
	int inputMax;
	char **inputChar = NULL;
	char *temp = NULL;

	printf("�Է��� �ܾ� �� �Է� : ");
	scanf_s("%d", &inputCnt);
	inputChar = (char**)malloc(sizeof(char*) * inputCnt);
	CheckMem(*inputChar);

	printf("�ܾ��� �ִ� ���� �Է� : ");
	scanf_s("%d", &inputMax);
	temp = (char *)malloc(sizeof(char) * inputMax + 1);
	CheckMem(temp);

	while (cnt < inputCnt)
	{
		inputChar[cnt] = (char *)malloc(sizeof(char) * inputMax + 1);
		CheckMem(inputChar[cnt]);
		memset(inputChar[cnt], 0, _msize(inputChar[cnt]));

		printf("�ܾ �Է��ϼ��� : ");
		while (1)
		{
			rewind(stdin);
			scanf_s("%[^\n]s", inputChar[cnt], _msize(inputChar[cnt]));
			if (strlen(inputChar[cnt]) != 0)
			{
				break;
			}
			else if (strcmp(inputChar[cnt],"") == 0)
			{
				break;
			}

			//else
			//{
			//	printf("\n�Է°��� ����, �ٽ� �Է��ϼ��� : ");
			//	continue;
			//}

			/*
			--------------------------------------------------------------
			����
			scanf_s�� ��ȯ���� ������ ""�̰�, 
			���� ����� �Ѿ�� ���ڸ� �Է¹��� ��쿡�� ""�� �Էµ�
			--------------------------------------------------------------
			*/
		}

		if (strcmp(inputChar[cnt], "") == 0)
		{
			cnt++;
			break;
		}

		for (int i = 0; i < strlen(inputChar[cnt]); i++)
		{
			inputChar[cnt][i] = tolower(inputChar[cnt][i]);
		}
		cnt++;
	}

	SortChar(inputChar, temp, cnt);
	PrintChar(inputChar, cnt);

	CheckFree(temp);
	if (inputChar != NULL)
	{
		for (int i = 0; i < cnt; i++)
		{
			free(inputChar[i]);
		}
		free(inputChar);
	}
	
	return;
}

void SortChar(char **inputChar, char *temp, int cnt)
{
	int index;
	for (int i = 0; i < cnt - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < cnt; j++)
		{
			if (strcmp(inputChar[index], inputChar[j])>0)
			{
				index = j;
			}
		}
		strcpy_s(temp, _msize(inputChar[i]), inputChar[i]);
		strcpy_s(inputChar[i], _msize(inputChar[index]), inputChar[index]);
		strcpy_s(inputChar[index], _msize(inputChar[index]), temp);
	}
}

void PrintChar(char **inputChar, int cnt)
{
	puts("\n���");
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(inputChar[i], " ") == 1)
		{
			printf("%s\n", inputChar[i]);
		}
	}
}

void CheckMem(char *mem)
{
	if (mem == NULL)
	{
		puts("Error!");
		exit(1);
	}
}

void CheckFree(char *mem)
{
	if (mem != NULL)
	{
		free(mem);
	}
}
