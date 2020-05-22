// Q. 사용자로부터 단어 하나를 입력받은 뒤, 그 문자열 내에 A부터 Z까지 알파벳이 각각 몇 개씩 등장하는지 세어 출력
// 대소문자는 같이 처리, 등장하지 않는 알파벳을 출력하지 않음, 알파벳 이외의 문자는 무시

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

	printf("단어 입력 : ");
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