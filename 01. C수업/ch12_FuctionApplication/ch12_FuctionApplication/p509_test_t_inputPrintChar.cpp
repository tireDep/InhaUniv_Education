// Q. 사용자로부터 최대 10개의 단어를 입력받아 정렬하는 프로그램을 작성하라
// 사전식 순서로 작은 단어가 앞에 와야한다.
// 단, 각각의 단어는 15글자를 넘지 않는다고 가정한다.
// 조건 
// - 종료는 enter키 입력
// - 입력은 소문자로만

// 완성 후 임의의 단어갯수와 임의의 단어 글자 수로 변경해서 풀어볼 것
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
	printf("입력할 단어 수 입력 : ");
	scanf_s("%d", &inputNum);
	char **inputChar = (char**)malloc(sizeof(char*) * inputNum);

	int inputMax;
	printf("단어의 최대 길이 입력 : ");
	scanf_s("%d", &inputMax);
	char *temp = (char *)malloc(sizeof(char)*inputMax);

	while (cnt < inputNum)
	{
		inputChar[cnt] = (char *)malloc(sizeof(char)*inputNum);
		rewind(stdin);
		printf("단어를 입력하세요 : ");
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

	puts("결과");
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