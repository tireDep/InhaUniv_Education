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
		printf("[메인화면]\n");
		printf("1. 데이터 추가  2. 검색&출력  3. 변경  4. 복구  5. 종료\n입력 : ");
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
			puts("프로그램 종료");
			return 0;
			break;

		default:
			printf("보기에 없는 숫자입니다. 재입력 해주세요.");
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

	printf("\n[데이터 입력]\n");
	printf("학생의 자리 입력 : ");
	scanf_s("%d", &newStudent->seatNum);
	printf("학생의 이름 입력 : ");
	scanf_s("%s", newStudent->name, sizeof(newStudent->name));

	if (_access("./nowFile.dat", 00) == 0)
	{
		/*
		두번째 입력부터 진행 되며,
		기존 데이터를 모두 불러온 후 입력받은 값의 중복체크와 정렬 후 파일에 덮어쓰기됨
		*/
		*headStu = NULL;
		*tailStu = *headStu;	// 데이터 초기화

		// CopyFile();	// todo

		int nodeCnt = 0;
		ReadData(headStu, tailStu, &nodeCnt);	// 기존에 저장되어 있는 값 읽어옴
		if (!CheckSameSeat(headStu, tailStu, newStudent)) // 중복 값 판별
		{
			SortData(headStu, nodeCnt);	// 데이터 정렬
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
		if (studentList->seatNum == 0)	break;	// 맨 마지막 개행 제거

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
			printf("동일한 좌석이 존재합니다. 입력을 종료합니다.\n");
			return true;
		}
		tempSearch = tempSearch->nextStudent;
	}
	(*tailStu)->nextStudent = newStudent;	// 동일좌석 존재 x시, 연결리스트 노드로 저장
	*tailStu = newStudent;
	return false;
}	// void CheckSameSeat()

void SortData(Student_s **headStu, int nodeCnt)
{
	/*
	정렬 방식 : 노드 연결을 바꾸는 것이 아니라 안의 값을 바꾸는 형식으로 진행함
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
		}	// while() : 내부 순환
	}	// while() : 전체 순환

}	// void SortData()

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