#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>	// _access()

struct Student_s
{
	int seatNum;
	char name[32];

	Student_s *nextStudent;
};

void CheckMem(Student_s *mem);
void CheckFree(Student_s *mem);

void AddStudent(Student_s **headStu, Student_s **tailStu);
void ReadData(Student_s **headStu, Student_s **tailStu, int *nodeCnt);
bool CheckSameSeat(Student_s **headStu, Student_s **tailStu, Student_s *newStudent);
void SortData(Student_s **headStu, int nodeCnt);

int CopyFile();

int main()
{
	Student_s *headStu = NULL;
	Student_s *tailStu = headStu;

	int inputNum;
	while (1)
	{
		printf("[����ȭ��]\n");
		printf("1. ������ �߰�  2. �˻�&���  3. ����  4. ����  5. ����\n�Է� : ");
		scanf_s("%d", &inputNum);

		switch (inputNum)
		{
		case 1:
			AddStudent(&headStu, &tailStu);
			break;
		case 2:
			// SearchAndPrint();
			break;
		case 3:
			// ChangeData();
			break;
		case 4:
			// RestoreData();
			// copyfile();	// todo
			break;
		case 5:
			puts("���α׷� ����");
			return 0;
			break;

		default:
			printf("���⿡ ���� �����Դϴ�. ���Է� ���ּ���.");
			break;
		}
		puts("");
	}
	
	CheckFree(headStu);
	CheckFree(tailStu);

	return 0;
}

void CheckMem(Student_s *mem)
{
	if (mem == NULL)
	{
		puts("Error!");
		return;
	}
	mem->nextStudent = NULL;
	memset(mem, 0, sizeof(mem));
}	// void CheckMem()

void CheckFree(Student_s *mem)
{
	if (mem != NULL)
		free(mem);
}	// CheckFree()

void AddStudent(Student_s **headStu, Student_s **tailStu)
{
	Student_s *newStudent;
	newStudent = (Student_s *)malloc(sizeof(Student_s));
	CheckMem(newStudent);

	printf("\n[������ �Է�]\n");
	printf("�л��� �ڸ� �Է� : ");
	scanf_s("%d", &newStudent->seatNum);
	printf("�л��� �̸� �Է� : ");
	scanf_s("%s", newStudent->name, sizeof(newStudent->name));

	if (_access("./nowFile.dat", 00) == 0)
	{
		/*
		�ι�° �Էº��� ���� �Ǹ�,
		���� �����͸� ��� �ҷ��� �� �Է¹��� ���� �ߺ�üũ�� ���� �� ���Ͽ� ������
		*/
		*headStu = NULL;
		*tailStu = *headStu;	// ������ �ʱ�ȭ

		// CopyFile();	// todo

		int nodeCnt = 0;
		ReadData(headStu, tailStu, &nodeCnt);	// ������ ����Ǿ� �ִ� �� �о��
		if (!CheckSameSeat(headStu, tailStu, newStudent)) // �ߺ� �� �Ǻ�
		{
			SortData(headStu, nodeCnt);	// ������ ����
		}
		else
			return;
	}
	else
	{
		*headStu = newStudent;
	}

	FILE *nowFp = NULL;
	fopen_s(&nowFp, "nowFile.dat", "wb");

	while (*headStu != NULL)
	{
		fprintf(nowFp, "%d %s\n", (*headStu)->seatNum, (*headStu)->name);
		(*headStu) = (*headStu)->nextStudent;
	}
	fclose(nowFp);

	return;
}	// void AddStudent()

void ReadData(Student_s **headStu, Student_s **tailStu, int *nodeCnt)
{
	FILE *readFp = NULL;
	fopen_s(&readFp, "nowFile.dat", "rb");
	if (readFp == NULL)
	{
		puts("Error!");
		return;
	}

	int intTemp = 0;
	char charTemp[32] = { 0 };
	while (!feof(readFp))
	{
		Student_s *studentList;
		studentList = (Student_s *)malloc(sizeof(Student_s));
		CheckMem(studentList);

		fscanf_s(readFp, "%d %s", &studentList->seatNum, studentList->name, sizeof(studentList));
		if (studentList->seatNum == 0)	break;	// �� ������ ���� ����

		if (*headStu == NULL)
		{
			*headStu = studentList;
			*tailStu = studentList;
		}
		else
		{
			(*tailStu)->nextStudent = studentList;
			*tailStu = studentList;
		}
		nodeCnt++;
	}
	fclose(readFp);
}	// void ReadData()

bool CheckSameSeat(Student_s **headStu, Student_s **tailStu, Student_s *newStudent)
{
	Student_s *tempSearch = *headStu;
	while (tempSearch != NULL)
	{
		if (tempSearch->seatNum == newStudent->seatNum)
		{
			printf("������ �¼��� �����մϴ�. �Է��� �����մϴ�.\n");
			return true;
		}
		tempSearch = tempSearch->nextStudent;
	}
	(*tailStu)->nextStudent = newStudent;	// �����¼� ���� x��, ���Ḯ��Ʈ ���� ����
	*tailStu = newStudent;
	return false;
}	// void CheckSameSeat()

void SortData(Student_s **headStu, int nodeCnt)
{
	/*
	���� ��� : ��� ������ �ٲٴ� ���� �ƴ϶� ���� ���� �ٲٴ� �������� ������
	*/
	Student_s *tempHead = *headStu;
	Student_s *swap = NULL;

	int tempNum = 0;
	char tempName[32] = { 0 };
	while (nodeCnt + 1 >= 0)
	{
		nodeCnt--;
		tempHead = *headStu;
		while (tempHead->nextStudent != NULL)
		{
			if (tempHead->seatNum > tempHead->nextStudent->seatNum)
			{
				tempNum = tempHead->seatNum;
				strcpy_s(tempName, 32, tempHead->name);

				tempHead->seatNum = tempHead->nextStudent->seatNum;
				strcpy_s(tempHead->name, 32, tempHead->nextStudent->name);

				tempHead->nextStudent->seatNum = tempNum;
				strcpy_s(tempHead->nextStudent->name, 32, tempName);
			}
			tempHead = tempHead->nextStudent;
		}	// while() : ���� ��ȯ
	}	// while() : ��ü ��ȯ

}	// void SortData()

int CopyFile()
{
	FILE *cpFile = NULL;
	FILE *dstFile = NULL;

	fopen_s(&cpFile, "nowFile.dat", "rb");
	fopen_s(&dstFile, "lastFile.dat", "wb");
	if (cpFile == NULL)
	{
		puts("���� ���� ����");
		return 0;
	}

	int intTemp = 0;
	char charTemp[128] = { 0 };
	int cnt = 0;
	fseek(cpFile, 0, SEEK_SET);
	while (!feof(cpFile))
	{
		fscanf_s(cpFile, "%d %s", &intTemp, charTemp, sizeof(charTemp));
		if (!feof(cpFile))fprintf(dstFile, "%d %s\n", intTemp, charTemp);
	}

	_fcloseall();
	return 0;
}