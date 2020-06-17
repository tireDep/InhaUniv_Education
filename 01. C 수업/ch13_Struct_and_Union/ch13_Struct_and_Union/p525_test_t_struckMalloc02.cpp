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

	School_s *pNext;
};

void InputStudent(School_s **pHead, School_s **pTail);
// School_s * InputStudent();
void SearchStudent(School_s *pHead, int cnt);
void PrintStudent(School_s *pHead, int cnt);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	int inputNum = 0;
	int inputStu = 0;
	int cnt = 0;

	School_s *pHead = NULL;
	School_s *pTail = pHead;

	while (1)
	{
		printf("\n메뉴선택\n");
		printf("1. 입력  2. 검색  3. 전체 출력  4. 종료\n");
		scanf_s("%d", &inputNum);

		switch (inputNum)
		{
		case 1:
			InputStudent(&pHead, &pTail);
			/*
			tempStu = InputStudent();
			if (pHead == NULL)
			{
				pHead = tempStu;
				pTail = tempStu;
			}
			else
			{
				pTail->pNext = tempStu;
				pTail = tempStu;
			}
			*/
			break;
		case 2:
			SearchStudent(pHead, cnt);
			break;
		case 3:
			PrintStudent(pHead, cnt);
			break;
		case 4:
			printf("프로그램 종료\n");
			if (pHead != NULL)
			{
				free(pHead);
			}
			free(pTail);
			exit(0);

		default:
			printf("에러\n");
			break;
		}
	}
	_CrtDumpMemoryLeaks();

	return 0;
}

void InputStudent(School_s **pHead, School_s **pTail)
{
	School_s *inputStu = NULL;
	inputStu = (School_s *)malloc(sizeof(School_s));
	if (inputStu == NULL)
	{
		printf("Error!");
		exit(0);
	}
	inputStu->pNext = NULL;
	memset(inputStu, 0, sizeof(inputStu));	// 초기화를 해줘야함!

	rewind(stdin);
	printf("\n학생 이름 입력 : ");
	scanf_s("%s", inputStu->name, sizeof(inputStu->name));

	rewind(stdin);
	printf("학생 번호 입력 : ");
	scanf_s("%d", &inputStu->num);

	rewind(stdin);
	printf("학생 성적 입력 : ");
	scanf_s("%d", &inputStu->score);

	if (*pHead == NULL) 
	{
		*pHead = inputStu;
		*pTail = inputStu;
	}
	else
	{
		(*pTail)->pNext = inputStu;
		*pTail = inputStu;
	}

	return;
}
/*
School_s *InputStudent()
{
	School_s *inputStu = NULL;
	inputStu = (School_s *)malloc(sizeof(School_s));
	if (inputStu == NULL)
	{
		printf("Error!");
		exit(0);
	}
	inputStu->pNext = NULL;

	rewind(stdin);
	printf("\n학생 이름 입력 : ");
	scanf_s("%s", inputStu->name, sizeof(inputStu->name));

	rewind(stdin);
	printf("학생 번호 입력 : ");
	scanf_s("%d", &inputStu->num);

	rewind(stdin);
	printf("학생 성적 입력 : ");
	scanf_s("%d", &inputStu->score);

	return inputStu;
}
// 이 경우에서 매개변수로 pHead와 pTail을 넘기면 
// inputStu가 함수가 끝나는 순간 사라지므로 NULL이 됨!!

*/

void SearchStudent(School_s *pHead, int cnt)
{
	School_s *searchStu = pHead;
	char searchName[32];
	printf("학생 이름 입력 : ");
	scanf_s("%s", searchName, sizeof(searchName));

	while (searchStu != NULL)
	{
		if (strcmp(searchStu->name, searchName) == 0)
		{
			printf("이름 : %s, 번호 : %d, 성적 : %d\n",
				searchStu->name, searchStu->num, searchStu->score);
			return;
		}
		searchStu = searchStu->pNext;
	}
	printf("검색결과가 없습니다.\n");
}

void PrintStudent(School_s *pHead, int cnt)
{
	School_s *printStu = pHead;
	while (printStu != NULL)
	{
		printf("이름 : %s, 번호 : %d, 성적 : %d\n", 
			printStu->name, printStu->num, printStu->score);
		printStu = printStu->pNext;
	}

}