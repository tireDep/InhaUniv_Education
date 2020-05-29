#pragma once

#define ARRSIZE 128

struct Student_s
{
	int seatNum;
	char name[ARRSIZE];

	Student_s *nextStudent;
};

void CheckMem(Student_s *mem);	// 메모리 할당 확인 함수
void CheckFree(Student_s *mem);	// 메모리 해제 확인 함수
void CheckFile(Student_s **headStu, Student_s **tailStu, int *nodeCnt);	// 기존 파일 존재하는지 확인 함수

void AddStudent(Student_s **headStu, Student_s **tailStu, int nodeCnt);	// 새로운 학생 입력 함수
int ReadData(Student_s **headStu, Student_s **tailStu);	// 기존 파일 내역을 링크드 리스트에 저장하는 함수
bool CheckSameSeat(Student_s **headStu, Student_s *newStudent, int checkNum);	// 중복숫자 입력 확인 함수
void SortData(Student_s **headStu, int nodeCnt);	// 링크드 리스트 정렬 함수
void WriteData(Student_s **headStu);	//	링크드 리스트의 내용을 파일로 출력하는 함수

void ChangeData(Student_s **headStu, Student_s **tailStu, int nodeCnt);	//	값 변경 함수
void CopyFile(char *dstFileName, char *srcFileName);	// 파일 복사 함수(savedata 생성)
void SearchAndPrint(Student_s **headStu);	// 검색 및 출력 함수