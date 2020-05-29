#pragma once

#define ARRSIZE 128

struct Student_s
{
	int seatNum;
	char name[ARRSIZE];

	Student_s *nextStudent;
};

void CheckMem(Student_s *mem);	// �޸� �Ҵ� Ȯ�� �Լ�
void CheckFree(Student_s *mem);	// �޸� ���� Ȯ�� �Լ�
void CheckFile(Student_s **headStu, Student_s **tailStu, int *nodeCnt);	// ���� ���� �����ϴ��� Ȯ�� �Լ�

void AddStudent(Student_s **headStu, Student_s **tailStu, int nodeCnt);	// ���ο� �л� �Է� �Լ�
int ReadData(Student_s **headStu, Student_s **tailStu);	// ���� ���� ������ ��ũ�� ����Ʈ�� �����ϴ� �Լ�
bool CheckSameSeat(Student_s **headStu, Student_s *newStudent, int checkNum);	// �ߺ����� �Է� Ȯ�� �Լ�
void SortData(Student_s **headStu, int nodeCnt);	// ��ũ�� ����Ʈ ���� �Լ�
void WriteData(Student_s **headStu);	//	��ũ�� ����Ʈ�� ������ ���Ϸ� ����ϴ� �Լ�

void ChangeData(Student_s **headStu, Student_s **tailStu, int nodeCnt);	//	�� ���� �Լ�
void CopyFile(char *dstFileName, char *srcFileName);	// ���� ���� �Լ�(savedata ����)
void SearchAndPrint(Student_s **headStu);	// �˻� �� ��� �Լ�