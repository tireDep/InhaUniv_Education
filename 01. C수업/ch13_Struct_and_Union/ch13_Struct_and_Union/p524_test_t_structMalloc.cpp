// Q. 번호, 이름, 성적을 입력받을 수 있는 구조체를 만들고
// 학생 수 10명인 반의 데이터를 입력받아 출력하는 코드 제작
// ex)
// 1. 입력	- 학생의 번호, 이름, 성적을 순차적으로 입력 받음
// 2. 검색	- 이름으로 해당 학생의 번호, 이름, 성적을 출력
// 3. 전체 출력	- 전체 학생의 번호, 이름 성적을 출력
// 4. 종료	- 프로그램 종료

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<crtdbg.h>

struct School_s
{
	char name[32];
	int num;
	int score;
};

void InputStudent(School_s *schoolStu, int *cnt, int *inputStu);
void SearchStudent(School_s *schoolStu, int cnt);
void PrintStudent(School_s *schoolStu, int cnt);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	int inputNum = 0;
	int inputStu = 0;
	int cnt = 0;
	printf("입력받을 학생 수 : ");
	scanf_s("%d", &inputStu);
	
	School_s *schoolStu = NULL;
	schoolStu = (School_s *)malloc(sizeof(School_s) * inputStu);
	if (schoolStu == NULL)
	{
		printf("Error!");
		exit(0);
	}

	while(1)
	{
		printf("\n메뉴선택\n");
		printf("1. 입력  2. 검색  3. 전체 출력  4. 종료\n");
		scanf_s("%d", &inputNum);
		
		switch (inputNum)
		{
		case 1:
			InputStudent(schoolStu, &cnt, &inputStu);
			break;
		case 2:
			SearchStudent(schoolStu, cnt);
			break;
		case 3:
			PrintStudent(schoolStu, cnt);
			break;
		case 4:
			printf("프로그램 종료\n");
			if (schoolStu != NULL)
			{
				free(schoolStu);
			}
			exit(0);

		default:
			printf("에러\n");
			break;
		}
	}
	_CrtDumpMemoryLeaks();
	return 0;
}

void InputStudent(School_s *schoolStu, int *cnt, int *inputStu)
{
	if (*cnt < *inputStu)
	{
		rewind(stdin);
		printf("\n학생 이름 입력 : ");
		scanf_s("%s", schoolStu[*cnt].name, sizeof(schoolStu[*cnt].name));

		rewind(stdin);
		printf("학생 번호 입력 : ");
		scanf_s("%d", &schoolStu[*cnt].num);

		rewind(stdin);
		printf("학생 성적 입력 : ");
		scanf_s("%d", &schoolStu[*cnt].score);

		*cnt += 1;
	}
	else
	{
		printf("입력 수 초과, 재입력\n");
		schoolStu = (School_s *)realloc(schoolStu, sizeof(schoolStu)*2);
		*inputStu = *inputStu * 2;
	}

	return;
}

void SearchStudent(School_s *schoolStu, int cnt)
{
	char searchName[32];
	printf("학생 이름 입력 : ");
	scanf_s("%s", searchName, sizeof(searchName));

	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(schoolStu[i].name, searchName)==0)
		{
			printf("\n이름 : %s, 번호 : %d, 성적 : %d\n", 
				schoolStu[i].name, schoolStu[i].num, schoolStu[i].score);
			return;
		}
	}

	printf("검색결과가 없습니다.\n");
}

void PrintStudent(School_s *schoolStu, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if(schoolStu[i].num!=0)
			printf("이름 : %s, 번호 : %d, 성적 : %d\n", 
				schoolStu[i].name, schoolStu[i].num, schoolStu[i].score);
	}
}