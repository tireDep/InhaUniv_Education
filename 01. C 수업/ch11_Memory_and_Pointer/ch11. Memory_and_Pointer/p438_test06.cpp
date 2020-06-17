// 438p
// Q, ������ �Է¹ް�, �� ������ŭ char *�� ������ ������ �� �ִ� �޸𸮸� ���� �Ҵ��մϴ�.
// �׸��� �Է��� ���ڿ��� �ִ� ���̸� �Է¹ް�, �ִ� ������ ���ڿ��� ������ �� �ִ� ũ���� �޸𸮸� ���� �Ҵ��Ͽ� �Է¹��� ���ڿ��� ������ ��
// ����ϴ� ���α׷� �ۼ�
// 


/*
������ �Է¹޾� �� ũ�⸸ŭ char * �޸� �����Ҵ�
�ִ� ���� �Է¹ް�, �� ũ�⸸ŭ �����Ҵ�
���ڿ��� ������ �� ���
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CheckError(char *mem);
void CheckFree(char **mem, int limitNum);

int main()
{
	int inputNum = 0;
	printf("�Է��� ���ڿ� �� : ");
	scanf_s("%d", &inputNum);

	int inputMax = 0;
	printf("�ִ� ���� : ");
	scanf_s("%d", &inputMax);

	char **stringArr = (char **)malloc(sizeof(char *) * inputNum);
	CheckError(*stringArr);

	for (int i = 0; i < inputNum; i++)
	{
		stringArr[i] = (char *)malloc(sizeof(char) * inputMax + 1);
		CheckError(stringArr[i]);

		do
		{
			rewind(stdin);
			scanf_s("%s", stringArr[i], inputMax + 1);
			//gets_s(stringArr[i], _msize(stringArr[i]));

		} while (strlen(stringArr[i]) == 0);

	}

	printf("\n��� : ");
	for (int i = 0; i < inputNum; i++)
	{
		printf("%s ", stringArr[i]);
	}
	puts("");

	CheckFree(stringArr,inputNum);

	return 0;
}

void CheckError(char *mem)
{
	if (mem == NULL)
	{
		puts("Error!");
		exit(1);
	}
}

void CheckFree(char **mem, int limitNum)
{
	if (mem != NULL)
	{
		for (int i = 0; i < limitNum; i++)
		{
			free(mem[i]);
		}
		free(mem);
	}
}