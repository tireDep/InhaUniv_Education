// 437p
// Q, �Ű������� char *�� �ڷḦ �޾Ƽ� ���ڿ��� ���̸� ����� ��ȯ�ϴ� �Լ��� �ۼ��ϼ���.
// �Լ��� �̸��� GetLength()�� �մϴ�.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int GetLength(char *string);

int main()
{
	char *inputString = NULL;
	inputString = (char *)malloc(128);
	if (inputString == NULL)
	{
		puts("Error!");
		return 0;
	}
	
	int result;
	printf("���ڿ� �Է� : ");
	gets_s(inputString, strlen(inputString));	
	// malloc, realloc �� ũ��� _msize() �̿�, but window������ ��� ����
	// strlen(), ���� �ѹ� �� ���� ����� ����

	result = GetLength(inputString);

	printf("���ڿ��� ���� : %d\n", result);

	if (inputString != NULL)
	{
		free(inputString);
	}
}

int GetLength(char *string)
{
	int cnt = 0;

	while (*(string + cnt) != '\0')
	{
		cnt++;
	}

	return cnt;
}