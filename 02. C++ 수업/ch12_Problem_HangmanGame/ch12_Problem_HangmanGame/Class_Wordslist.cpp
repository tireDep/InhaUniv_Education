#include<iostream>
#include<string>
#include<Windows.h>
#include"Class_Wordslist.h"

using std::string;
using std::cout;
using std::endl;

enum { eTry = 0, eCleaR = 0, eDead = 7 };

WORDSLIST_C::WORDSLIST_C()
{
	tryCnt = eTry;
	clearCnt = eCleaR;	// 정답 횟수
	deadCnt = eDead;	// 최대 시도 횟수
}

WORDSLIST_C::~WORDSLIST_C()
{
	delete[] iAnswerCheck;
}

string WORDSLIST_C::GetAnswerWords()
{
	return sAnswerWords;
}

int WORDSLIST_C::GetAnswerCheck(int i)
{
	return iAnswerCheck[i];
}

void WORDSLIST_C::PrintBoard()
{
	for (int i = 0; i < sStrLen; i++)
	{
		if (iAnswerCheck[i] == 0)
			cout << "*" << " ";
		else
			cout << sAnswerWords[i] << " ";
	}
	cout << endl;
}

void WORDSLIST_C::CompareInputAlpha(char inputAlpha)
{
	bool isAns = false;
	tryCnt++;
	for (int i = 0; i < sStrLen; i++)
	{
		if (sAnswerWords[i] == inputAlpha)
		{
			if (iAnswerCheck[i] == 1)
			{
				cout << "해당 알파벳이 이미 입력됨\n\n";
				Sleep(500);
				system("cls");
				return;
			}
			iAnswerCheck[i] = 1;
			clearCnt++;
			isAns = true;
		}
	}

	if (isAns == false)
	{
		deadCnt--;
		cout << "남은 실패 횟수 : " << deadCnt << endl << endl;
		// if(deadCnt == 5)
		// 	std::cout << "----------\n";
		// else if (deadCnt == 4)
		// 	std::cout << "    -\n    -\n    -\n    -\n";
		// else if (deadCnt == 3)
		// 	std::cout << "    ---\n    ---\n    ---\n    ";
		// else if (deadCnt == 2)
		// 	std::cout << "    -\n    -\n    -\n    -\n    -\n";
		// else if (deadCnt == 1)
		// 	std::cout << "    -\n    -\n    -\n    -\n    -\n";
	}
	else
		cout << "단어 존재" << endl;

	Sleep(250);
	system("cls");
}

void WORDSLIST_C::SetValue(string newStr)
{
	tryCnt = eTry;
	clearCnt = eCleaR;	// 정답 횟수
	sStrLen = newStr.length();
	deadCnt = eDead;	// 최대 시도 횟수

	sAnswerWords = newStr;
	iAnswerCheck = new int[sStrLen];

	for (int i = 0; i < sStrLen; i++)
		iAnswerCheck[i] = 0;	// 초기화
}

int WORDSLIST_C::GetDeadCnt()
{
	return deadCnt;
}

int WORDSLIST_C::GetClrCnt()
{
	return clearCnt;
}

int WORDSLIST_C::GetLen()
{
	return sStrLen;
}

int WORDSLIST_C::GetTry()
{
	return tryCnt;
}