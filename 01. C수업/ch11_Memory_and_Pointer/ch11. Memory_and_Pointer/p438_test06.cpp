// 438p
// Q, 정수를 입력받고, 그 개수만큼 char *를 여러개 저장할 수 있는 메모리를 동적 할당합니다.
// 그리고 입력할 문자열의 최대 길이를 입력받고, 최대 길이의 문자열을 저장할 수 있는 크기의 메모리를 동적 할당하여 입력받은 문자열을 저장한 후
// 출력하는 프로그램 작성
// 


/*
정수를 입력받아 그 크기만큼 char * 메모리 동적할당
최대 길이 입력받고, 그 크기만큼 동적할당
문자열을 저장한 후 출력
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CheckError(char *mem);
void CheckFree(char **mem, int limitNum);

int main()
{
	int inputNum = 0;
	printf("입력할 문자열 수 : ");
	scanf_s("%d", &inputNum);

	int inputMax = 0;
	printf("최대 길이 : ");
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

	printf("\n결과 : ");
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