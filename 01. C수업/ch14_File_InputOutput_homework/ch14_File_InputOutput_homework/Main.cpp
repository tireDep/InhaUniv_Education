#include "BasicHeader.h"
#include "FuncHeader.h"

int main()
{
	Student_s *headStu = NULL;
	Student_s *tailStu = headStu;
	int inputNum;
	int nodeCnt = 0;

	while (1)
	{
		printf("[����ȭ��]\n");
		printf("1. ������ �߰�  2. �˻�&���  3. ����  4. ����  5. ����\n�Է� : ");
		scanf_s("%d", &inputNum);

		CheckFile(&headStu, &tailStu, &nodeCnt);
		switch (inputNum)
		{
		case 1:
			AddStudent(&headStu, &tailStu, nodeCnt);
			break;
		case 2:
			SearchAndPrint(&headStu);
			break;
		case 3:
			ChangeData(&headStu, &tailStu, nodeCnt);
			break;
		case 4:
			CopyFile("nowFile.dat", "lastFile.dat");
			printf("���� ����\n");
			break;
		case 5:
			puts("���α׷� ����");
			return 0;
			break;

		default:
			printf("���⿡ ���� ����, ���Է� �ʿ�\n");
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
		puts("Error!_malloc");
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

void AddStudent(Student_s **headStu, Student_s **tailStu, int nodeCnt)
{
	Student_s *newStudent;
	newStudent = (Student_s *)malloc(sizeof(Student_s));
	CheckMem(newStudent);

	printf("\n[������ �Է�]\n");
	printf("�л��� �ڸ� �Է� : ");
	scanf_s("%d", &newStudent->seatNum);
	printf("�л��� �̸� �Է� : ");
	scanf_s("%s", newStudent->name, sizeof(newStudent->name));

	if (!CheckSameSeat(headStu, newStudent, nodeCnt)) // �ߺ� �� �Ǻ�
	{
		CopyFile("lastFile.dat", "nowFile.dat");	// save���� ����
		(*tailStu)->nextStudent = newStudent;
		*tailStu = newStudent;	// �����¼� ���� x��, ���Ḯ��Ʈ ���� ����
		SortData(headStu, nodeCnt);	// ������ ����
	}
	else if (_access("./nowFile.dat", 00) != 0)	// ù �Է��� ���
		*headStu = newStudent;
	else
		return;

	WriteData(headStu);

	return;
}	// void AddStudent()

int ReadData(Student_s **headStu, Student_s **tailStu)
{
	FILE *readFp = NULL;
	fopen_s(&readFp, "nowFile.dat", "rb");
	if (readFp == NULL)
	{
		puts("Error!_File isn't here");
		return 0;
	}

	int nodeCnt = 0;
	int intTemp = 0;
	char charTemp[ARRSIZE] = { 0 };
	while (!feof(readFp))
	{
		Student_s *studentList;
		studentList = (Student_s *)malloc(sizeof(Student_s));
		CheckMem(studentList);

		fscanf_s(readFp, "%d %s\n", &studentList->seatNum, studentList->name, sizeof(studentList) * 2);
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
	nodeCnt += 1;
	fclose(readFp);

	return nodeCnt;
}	// void ReadData()

bool CheckSameSeat(Student_s **headStu, Student_s *newStudent, int checkNum)
{
	int cntNum = checkNum;
	if (checkNum == 0) return true;
	else if (checkNum == 1) cntNum = 0;
	Student_s *tempSearch = *headStu;
	while (tempSearch != NULL)
	{
		if (tempSearch->seatNum == newStudent->seatNum)
		{
			if (checkNum <= cntNum)
			{
				printf("���� �¼� ����, �Է� ����\n");
				return true;
			}
			cntNum++;
		}
		tempSearch = tempSearch->nextStudent;
	}

	return false;
}	// void CheckSameSeat()

void SortData(Student_s **headStu, int nodeCnt)
{
	Student_s *tempHead = *headStu;
	Student_s *swap = NULL;
	int tempNum = 0;
	char tempName[ARRSIZE] = { 0 };
	while (nodeCnt >= 0)
	{
		nodeCnt--;
		tempHead = *headStu;
		while (tempHead->nextStudent != NULL)
		{
			if (tempHead->seatNum > tempHead->nextStudent->seatNum)
			{
				// ���� ��� : ��� ������ �ٲٴ� ���� �ƴ϶� ���� ���� �ٲٴ� �������� ������
				tempNum = tempHead->seatNum;
				strcpy_s(tempName, ARRSIZE, tempHead->name);

				tempHead->seatNum = tempHead->nextStudent->seatNum;
				strcpy_s(tempHead->name, ARRSIZE, tempHead->nextStudent->name);

				tempHead->nextStudent->seatNum = tempNum;
				strcpy_s(tempHead->nextStudent->name, ARRSIZE, tempName);
			}
			tempHead = tempHead->nextStudent;
		}	// while() : ���� ��ȯ
	}	// while() : ��ü ��ȯ

}	// void SortData()

void WriteData(Student_s **headStu)
{
	FILE *nowFp = NULL;
	fopen_s(&nowFp, "nowFile.dat", "wb");

	Student_s *inputStu = *headStu;
	while (inputStu != NULL)
	{
		fprintf(nowFp, "%d %s\n", inputStu->seatNum, inputStu->name);
		inputStu = inputStu->nextStudent;
	}
	fclose(nowFp);
}	// void WriteData()

void SearchAndPrint(Student_s **headStu)
{
	Student_s *searchTemp = NULL;
	searchTemp = *headStu;

	int check = 0;
	int inputNum = 0;
	char inputName[ARRSIZE] = { 0 };
	printf("\n[������ �˻�]\n");
	printf("\n1. ��ȣ�� �˻�  2. �̸����� �˻�\n�Է� : ");
	scanf_s("%d", &inputNum);

	if (inputNum == 1)
	{
		printf("\n�˻��� ��ȣ�� �Է� : ");
		scanf_s("%d", &inputNum);
		printf("\n[�˻����]\n");
		while (searchTemp!=NULL)
		{
			if (searchTemp->seatNum == inputNum)
			{
				PrintData(searchTemp, &check);
			}
			searchTemp = searchTemp->nextStudent;
		}
	}
	else if (inputNum == 2)
	{
		printf("\n�˻��� �̸��� �Է� : ");
		scanf_s("%s", inputName, sizeof(inputName));
		printf("\n[�˻����]\n");
		while (searchTemp != NULL)
		{
			if (strcmp(searchTemp->name,inputName)==0)
			{
				PrintData(searchTemp, &check);
			}
			searchTemp = searchTemp->nextStudent;
		}

	}
	else
		printf("\n�߸��� �� �Է�\n");

	if (check == 0)
		printf("\n�ش簪�� �������� ����\n");

}	// void SearchAndPrint()

void PrintData(Student_s *searchTemp, int *check)
{
	printf("��ȣ : %d �̸� : %s\n", searchTemp->seatNum, searchTemp->name);
	(*check)++;
}	// void PrintData()

void ChangeData(Student_s **headStu, Student_s **tailStu, int nodeCnt)
{
	Student_s *changeStu = *headStu;
	int inputNum = 0;
	char inputChar[ARRSIZE] = { 0 };
	printf("\n[������ ����]\n");
	printf("������ �ڸ���ȣ : ");
	scanf_s("%d", &inputNum);

	while (changeStu != NULL)
	{
		if (inputNum == changeStu->seatNum)
		{
			printf("\n�ٲ� ��ȣ �Է� : ");
			scanf_s("%d", &inputNum);
			printf("�ٲ� �̸� �Է� : ");
			scanf_s("%s", inputChar, sizeof(inputChar));

			changeStu->seatNum = inputNum;
			strcpy_s(changeStu->name, ARRSIZE, inputChar);

			if (!CheckSameSeat(headStu, changeStu, 1)) // �ߺ� �� �Ǻ�
			{
				CopyFile("lastFile.dat", "nowFile.dat");
				SortData(headStu, nodeCnt);	// ������ ����
				WriteData(headStu);
				printf("���� �Ϸ�\n");
			}
			return;
		}
		changeStu = changeStu->nextStudent;
	}
	printf("�ش� ��ȣ�� �������� ����\n");
	return;
}	// void ChangeData()

void CopyFile(char *dstFileName, char *srcFileName)
{
	FILE *srcFile = NULL;
	FILE *dstFile = NULL;
	fopen_s(&dstFile, dstFileName, "wb");
	fopen_s(&srcFile, srcFileName, "rb");
	if (srcFile == NULL)
	{
		puts("\n���� ���� ����\n");
		return;
	}

	int intTemp = 0;
	char charTemp[128] = { 0 };
	fseek(srcFile, 0, SEEK_SET);
	while (!feof(srcFile))
	{
		fscanf_s(srcFile, "%d %s", &intTemp, charTemp, sizeof(charTemp));
		if (!feof(srcFile))fprintf(dstFile, "%d %s\n", intTemp, charTemp);
	}
	_fcloseall();
}	// int CopyFile()

void CheckFile(Student_s **headStu, Student_s **tailStu, int *nodeCnt)
{
	if (_access("./nowFile.dat", 00) == 0)
	{
		*headStu = NULL;
		*tailStu = *headStu;	// ������ �ʱ�ȭ
		*nodeCnt = ReadData(headStu, tailStu);	// ������ ����Ǿ� �ִ� �� �о��
	}
}	// void CheckFile()