#pragma once

void SetPaul(int *paul);
void SetVal(int *ball, int *strike, int *checkCnt, int *checkZero);
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

void InputNumber(int *inputArr, int inputNum);	// ���� -> �迭 ����
void PrintScore(char *scoreName, int score);	// ���� ���