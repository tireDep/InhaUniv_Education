#pragma once

void SetPaul(int *paul);
void SetVal(int *ball, int *strike, int *checkCnt);
void SetNumber(int *ansArr);
// 변수 초기화

bool CheckPaul(int *paul);	// 파울 체크
							/*
							파울조건
							- 숫자가 3개가 아닐 경우
							- 숫자에 0이 들어간 경우(단, 0xxx로 입력할 경우 xxx로 입력되기 때문에 열외)
							- 중복된 값이 들어간 경우
							*/
int CheckTwice(int *arr, int maxI, int pos);	// 중복 체크
void CheckAnswer(int *answerArr, int *inputArr, int arrSize, int *strike, int *ball);	// 정답 체크

bool IsPaul(int *inputArr, int arrSize, int *paul, int _isPaul, char *string);

void InputNumber(int *inputNum, int *checkCnt, int *paul);
void InputNumberArr(int *inputArr, int inputNum);	// 숫자 -> 배열 저장
bool CheckScore(int *answerArr, int *strike, int *ball);	// 점수 체크
void PrintScore(char *scoreName, int score);	// 점수 출력

bool CheckRestart(); // 재시작