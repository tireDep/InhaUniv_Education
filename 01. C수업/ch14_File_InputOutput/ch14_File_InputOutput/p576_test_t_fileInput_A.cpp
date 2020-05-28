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

void AddStudent(Student_s **headStu, Student_s **tailStu);
int CopyFile();

int main()
{
	Student_s *headStu = NULL;
	Student_s *tailStu = headStu;

	int inputNum;
	int checkNum = 0;
	while (1)
	{
		printf("[메인화면]\n");
		printf("1. 데이터 추가  2. 검색&출력  3. 변경  4. 복구  5. 종료\n입력 : ");
		scanf_s("%d", &inputNum);

		switch (inputNum)
		{
		case 1:
		{
			AddStudent(&headStu, &tailStu);
			checkNum++;
			break;
		}
		case 2:
			// SearchAndPrint();
			break;
		case 3:
			// ChangeData();
			break;
		case 4:
			// RestoreData();
			// copyfile();
			break;
		case 5:
			puts("프로그램 종료");
			return 0;
			break;

		default:
			printf("보기에 없는 숫자입니다. 재입력 해주세요.");
			break;
		}
		puts("");
	}
	
	if (headStu != NULL)
		free(headStu);
	if (tailStu != NULL)
		free(tailStu);

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
}

// sort 작성
void AddStudent(Student_s **headStu, Student_s **tailStu)
{
	Student_s *newStudent;
	newStudent = (Student_s *)malloc(sizeof(Student_s));
	CheckMem(newStudent);

	printf("\n[데이터 입력]\n");
	printf("학생의 자리 입력 : ");
	scanf_s("%d", &newStudent->seatNum);
	printf("학생의 이름 입력 : ");
	scanf_s("%s", newStudent->name, sizeof(newStudent->name));

	// ---------------------------------------------------------------------------------------
	// InputLastData();

	if (_access("./nowFile.dat", 00)==0)	// 두번째 입력부터 실행되어야 함!!
	{
		*headStu = NULL;
		*tailStu = *headStu;
		// 데이터 초기화

		FILE *readFp = NULL;
		// CopyFile();

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
			if (studentList->seatNum == 0)	break;	// NULL 제거

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
		}
		fclose(readFp);
		// ==============================================================
		Student_s *tempSearch = *headStu;
		while (tempSearch != NULL)
		{
			if (tempSearch->seatNum == newStudent->seatNum)
			{
				printf("동일한 좌석이 존재합니다. 입력을 종료합니다.\n");
				return;
			}
			tempSearch = tempSearch->nextStudent;
		}
		(*tailStu)->nextStudent = newStudent;
		*tailStu = newStudent;

		// =======================================================
		// sort()
		Student_s *tempHead = *headStu;
		Student_s *swap = NULL;
		while (tempHead->nextStudent != NULL)
		{
			if (tempHead->seatNum > tempHead->nextStudent->seatNum)
			{
				swap = tempHead;
				tempHead = tempHead->nextStudent;
				swap->nextStudent = tempHead->nextStudent;
				tempHead->nextStudent = swap;
			}
			tempHead = tempHead->nextStudent;
		}
	}
	// ---------------------------------------------------------------------------------------

	FILE *nowFp = NULL;
	fopen_s(&nowFp, "nowFile.dat", "ab");
	fprintf(nowFp, "%d %s\n", newStudent->seatNum, newStudent->name);
	fclose(nowFp);
	// 파일 입력
	return;
}

int CopyFile()
{
	FILE *cpFile = NULL;
	FILE *dstFile = NULL;

	fopen_s(&cpFile, "nowFile.dat", "rb");
	fopen_s(&dstFile, "lastFile.dat", "wb");
	if (cpFile == NULL)
	{
		puts("파일 복사 에러");
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