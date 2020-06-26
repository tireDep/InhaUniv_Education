#pragma once

using std::string;

class WORDSLIST_C
{
private:
	string sAnswerWords;	// ���� �ܾ�
	int *iAnswerCheck;	// ��� ���� �迭
	int sStrLen;	// �ܾ� ����
	int tryCnt;	// �õ� Ƚ��
	int deadCnt;	// ���� ���� Ƚ��
	int clearCnt; // ���� Ƚ��

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