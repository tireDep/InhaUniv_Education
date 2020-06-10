// Q. ��ȣ, �̸�, ������ �Է¹��� �� �ִ� ����ü�� �����
// �л� �� 10���� ���� �����͸� �Է¹޾� ����ϴ� �ڵ� ����
// ex)
// 1. �Է�	- �л��� ��ȣ, �̸�, ������ ���������� �Է� ����
// 2. �˻�	- �̸����� �ش� �л��� ��ȣ, �̸�, ������ ���
// 3. ��ü ���	- ��ü �л��� ��ȣ, �̸� ������ ���
// 4. ����	- ���α׷� ����

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
		printf("\n�޴�����\n");
		printf("1. �Է�  2. �˻�  3. ��ü ���  4. ����\n");
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
			printf("���α׷� ����\n");
			if (pHead != NULL)
			{
				free(pHead);
			}
			free(pTail);
			exit(0);

		default:
			printf("����\n");
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
	memset(inputStu, 0, sizeof(inputStu));	// �ʱ�ȭ�� �������!

	rewind(stdin);
	printf("\n�л� �̸� �Է� : ");
	scanf_s("%s", inputStu->name, sizeof(inputStu->name));

	rewind(stdin);
	printf("�л� ��ȣ �Է� : ");
	scanf_s("%d", &inputStu->num);

	rewind(stdin);
	printf("�л� ���� �Է� : ");
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
	printf("\n�л� �̸� �Է� : ");
	scanf_s("%s", inputStu->name, sizeof(inputStu->name));

	rewind(stdin);
	printf("�л� ��ȣ �Է� : ");
	scanf_s("%d", &inputStu->num);

	rewind(stdin);
	printf("�л� ���� �Է� : ");
	scanf_s("%d", &inputStu->score);

	return inputStu;
}
// �� ��쿡�� �Ű������� pHead�� pTail�� �ѱ�� 
// inputStu�� �Լ��� ������ ���� ������Ƿ� NULL�� ��!!

*/

void SearchStudent(School_s *pHead, int cnt)
{
	School_s *searchStu = pHead;
	char searchName[32];
	printf("�л� �̸� �Է� : ");
	scanf_s("%s", searchName, sizeof(searchName));

	while (searchStu != NULL)
	{
		if (strcmp(searchStu->name, searchName) == 0)
		{
			printf("�̸� : %s, ��ȣ : %d, ���� : %d\n",
				searchStu->name, searchStu->num, searchStu->score);
			return;
		}
		searchStu = searchStu->pNext;
	}
	printf("�˻������ �����ϴ�.\n");
}

void PrintStudent(School_s *pHead, int cnt)
{
	School_s *printStu = pHead;
	while (printStu != NULL)
	{
		printf("�̸� : %s, ��ȣ : %d, ���� : %d\n", 
			printStu->name, printStu->num, printStu->score);
		printStu = printStu->pNext;
	}

}