#pragma once

using std::string;

class WORDSLIST_C
{
private:
	string sAnswerWords;	// 정답 단어
	int *iAnswerCheck;	// 출력 제어 배열
	int sStrLen;	// 단어 길이
	int tryCnt;	// 시도 횟수
	int deadCnt;	// 실패 제한 횟수
	int clearCnt; // 성공 횟수

public:
	WORDSLIST_C();
	~WORDSLIST_C();

	string GetAnswerWords();
	int GetAnswerCheck(int i);
	void PrintBoard();
	void CompareInputAlpha(char inputAlpha);

	void SetValue(string newStr);
	int GetDeadCnt();
	int GetClrCnt();
	int GetLen();
	int GetTry();
};