// Q. 사용자로부터 최대 10개의 단어를 입력받아 정렬하는 프로그램을 작성하라
// 사전식 순서로 작은 단어가 앞에 와야한다.
// 단, 각각의 단어는 15글자를 넘지 않는다고 가정한다.
// 조건 
// - 종료는 enter키 입력
// - 입력은 소문자로만

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define ARRSIZE 15

void Method_1();

int main()
{
	Method_1();
	return 0;
}

void Method_1()
{
	int cnt = 0;
	char inputChar[ARRSIZE][15] = { 0 };
	char temp[15] = { 0 };
	while (cnt < ARRSIZE)
	{
		printf("단어를 입력하세요 : ");
		rewind(stdin);
		gets_s(inputChar[cnt], 15);
		if (strcmp(inputChar[cnt], "") == 0)
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
	for (int i = 0; i < ARRSIZE - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < ARRSIZE; j++)
		{
			if (strcmp(inputChar[index], inputChar[j])>0)
			{
				index = j;
			}
		}
		strcpy_s(temp, inputChar[i]);
		strcpy_s(inputChar[i], inputChar[index]);
		strcpy_s(inputChar[index], temp);
	}
	puts("결과");
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (strcmp(inputChar[i], " ") == 1)
		{
			printf("%s\n", inputChar[i]);
		}
	}
}
