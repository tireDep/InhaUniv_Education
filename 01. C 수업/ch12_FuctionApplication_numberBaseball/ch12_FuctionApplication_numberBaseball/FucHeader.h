#pragma once

void SetPaul(int *paul);
void SetVal(int *ball, int *strike, int *checkCnt);
void SetNumber(int *ansArr);
// ���� �ʱ�ȭ

bool CheckPaul(int *paul);	// �Ŀ� üũ
							/*
							�Ŀ�����
							- ���ڰ� 3���� �ƴ� ���
							- ���ڿ� 0�� �� ���(��, 0xxx�� �Է��� ��� xxx�� �ԷµǱ� ������ ����)
							- �ߺ��� ���� �� ���
							*/
int CheckTwice(int *arr, int maxI, int pos);	// �ߺ� üũ
void CheckAnswer(int *answerArr, int *inputArr, int arrSize, int *strike, int *ball);	// ���� üũ

bool IsPaul(int *inputArr, int arrSize, int *paul, int _isPaul, char *string);

void InputNumber(int *inputNum, int *checkCnt, int *paul);
void InputNumberArr(int *inputArr, int inputNum);	// ���� -> �迭 ����
bool CheckScore(int *answerArr, int *strike, int *ball);	// ���� üũ
void PrintScore(char *scoreName, int score);	// ���� ���

bool CheckRestart(); // �����