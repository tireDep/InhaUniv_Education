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
	printf("�Է¹��� �л� �� : ");
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
		printf("\n�޴�����\n");
		printf("1. �Է�  2. �˻�  3. ��ü ���  4. ����\n");
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
			printf("���α׷� ����\n");
			if (schoolStu != NULL)
			{
				free(schoolStu);
			}
			exit(0);

		default:
			printf("����\n");
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
		printf("\n�л� �̸� �Է� : ");
		scanf_s("%s", schoolStu[*cnt].name, sizeof(schoolStu[*cnt].name));

		rewind(stdin);
		printf("�л� ��ȣ �Է� : ");
		scanf_s("%d", &schoolStu[*cnt].num);

		rewind(stdin);
		printf("�л� ���� �Է� : ");
		scanf_s("%d", &schoolStu[*cnt].score);

		*cnt += 1;
	}
	else
	{
		printf("�Է� �� �ʰ�, ���Է�\n");
		schoolStu = (School_s *)realloc(schoolStu, sizeof(schoolStu)*2);
		*inputStu = *inputStu * 2;
	}

	return;
}

void SearchStudent(School_s *schoolStu, int cnt)
{
	char searchName[32];
	printf("�л� �̸� �Է� : ");
	scanf_s("%s", searchName, sizeof(searchName));

	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(schoolStu[i].name, searchName)==0)
		{
			printf("\n�̸� : %s, ��ȣ : %d, ���� : %d\n", 
				schoolStu[i].name, schoolStu[i].num, schoolStu[i].score);
			return;
		}
	}

	printf("�˻������ �����ϴ�.\n");
}

void PrintStudent(School_s *schoolStu, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if(schoolStu[i].num!=0)
			printf("�̸� : %s, ��ȣ : %d, ���� : %d\n", 
				schoolStu[i].name, schoolStu[i].num, schoolStu[i].score);
	}
}