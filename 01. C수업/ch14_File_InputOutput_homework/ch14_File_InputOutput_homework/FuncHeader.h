#pragma once

#define ARRSIZE 32

struct Student_s
{
	int seatNum;
	char name[ARRSIZE];

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

void CheckFile(Student_s **headStu, Student_s **tailStu, int *nodeCnt);