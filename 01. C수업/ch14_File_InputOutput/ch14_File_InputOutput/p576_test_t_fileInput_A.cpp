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

void AddStudent(Student_s **headStu, Student_s **tailStu, int nodeCnt);
int ReadData(Student_s **headStu, Student_s **tailStu);
bool CheckSameSeat(Student_s **headStu, Student_s *newStudent, int checkNum);
void SortData(Student_s **headStu, int nodeCnt);
void WriteData(Student_s **headStu);

void ChangeData(Student_s **headStu, Student_s **tailStu, int nodeCnt);

void CopyFile(char *dstFileName, char *srcFileName);

void CheckFile(Student_s **headStu, Student_s **tailStu, int *nodeCnt)
{
	if (_access("./nowFile.dat", 00) == 0)
	{
		*headStu = NULL;
		*tailStu = *headStu;	// 데이터 초기화
		*nodeCnt = ReadData(headStu, tailStu);	// 기존에 저장되어 있는 값 읽어옴
	}
}

int main()
{
	Student_s *headStu = NULL;
	Student_s *tailStu = headStu;
	int inputNum;
	int nodeCnt = 0;

	while (1)
	{
		CheckFile(&headStu, &tailStu, &nodeCnt);
		printf("[메인화면]\n");
		printf("1. 데이터 추가  2. 검색&출력  3. 변경  4. 복구  5. 종료\n입력 : ");
		scanf_s("%d", &inputNum);

		switch (inputNum)
		{
		case 1:
			AddStudent(&headStu, &tailStu, nodeCnt);
			break;
		case 2:
			// SearchAndPrint();
			break;
		case 3:
			ChangeData(&headStu, &tailStu ,nodeCnt);
			break;
		case 4:
			CopyFile("nowFile.dat", "lastFile.dat");
			printf("파일이 복구되었습니다\n");
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

void AddStudent(Student_s **headStu, Student_s **tailStu, int nodeCnt)
{
	if (_access("./nowFile.dat", 00) == 0)
	{
		CopyFile("lastFile.dat", "nowFile.dat");	// save파일 생성
	}

	Student_s *newStudent;
	newStudent = (Student_s *)malloc(sizeof(Student_s));
	CheckMem(newStudent);

	printf("\n[데이터 입력]\n");
	printf("학생의 자리 입력 : ");
	scanf_s("%d", &newStudent->seatNum);
	printf("학생의 이름 입력 : ");
	scanf_s("%s", newStudent->name, sizeof(newStudent->name));

	if (!CheckSameSeat(headStu, newStudent, nodeCnt)) // 중복 값 판별
	{
		(*tailStu)->nextStudent = newStudent;	
		*tailStu = newStudent;	// 동일좌석 존재 x시, 연결리스트 노드로 저장
		SortData(headStu, nodeCnt);	// 데이터 정렬
	}
	else
		*headStu = newStudent;

	WriteData(headStu);

	return;
}	// void AddStudent()

int ReadData(Student_s **headStu, Student_s **tailStu)
{
	FILE *readFp = NULL;
	fopen_s(&readFp, "nowFile.dat", "rb");
	if (readFp == NULL)
	{
		puts("Error!");
		return 0;
	}

	int nodeCnt = 0;
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
				printf("동일한 좌석이 존재합니다. 입력을 종료합니다.\n");
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
	/*
	정렬 방식 : 노드 연결을 바꾸는 것이 아니라 안의 값을 바꾸는 형식으로 진행함
	*/
	Student_s *tempHead = *headStu;
	Student_s *swap = NULL;

	int tempNum = 0;
	char tempName[32] = { 0 };
	while (nodeCnt >= 0)
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
}

void ChangeData(Student_s **headStu, Student_s **tailStu, int nodeCnt)
{
	CopyFile("lastFile.dat", "nowFile.dat");
	Student_s *changeStu = *headStu;
	int inputNum = 0;
	char inputChar[32] = { 0 };
	rewind(stdin);
	printf("변경할 자리번호 : ");
	scanf_s("%d", &inputNum);

	while (changeStu != NULL)
	{
		if (inputNum == changeStu->seatNum)
		{
			printf("바꿀 번호 입력 : ");
			scanf_s("%d", &inputNum);
			printf("바꿀 이름 입력 : ");
			scanf_s("%s", inputChar, sizeof(inputChar));

			changeStu->seatNum = inputNum;
			strcpy_s(changeStu->name, 32, inputChar);

			if (!CheckSameSeat(headStu, changeStu, 1)) // 중복 값 판별
			{
				SortData(headStu, nodeCnt);	// 데이터 정렬
				WriteData(headStu);
			}
			return;
		}
		changeStu = changeStu->nextStudent;
	}
	printf("해당 번호가 존재하지 않습니다.");
	return;
}

void CopyFile(char *dstFileName, char *srcFileName)
{
	FILE *srcFile = NULL;
	FILE *dstFile = NULL;
	fopen_s(&dstFile, dstFileName, "wb");
	fopen_s(&srcFile, srcFileName, "rb");
	if (srcFile == NULL)
	{
		puts("파일 복사 에러");
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