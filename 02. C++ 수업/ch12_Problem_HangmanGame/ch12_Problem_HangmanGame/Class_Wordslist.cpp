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
	clearCnt = eCleaR;	// ���� Ƚ��
	deadCnt = eDead;	// �ִ� �õ� Ƚ��
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
				cout << "�ش� ���ĺ��� �̹� �Էµ�\n\n";
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
		cout << "���� ���� Ƚ�� : " << deadCnt << endl << endl;
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
		cout << "�ܾ� ����" << endl;

	Sleep(250);
	system("cls");
}

void WORDSLIST_C::SetValue(string newStr)
{
	tryCnt = eTry;
	clearCnt = eCleaR;	// ���� Ƚ��
	sStrLen = newStr.length();
	deadCnt = eDead;	// �ִ� �õ� Ƚ��

	sAnswerWords = newStr;
	iAnswerCheck = new int[sStrLen];

	for (int i = 0; i < sStrLen; i++)
		iAnswerCheck[i] = 0;	// �ʱ�ȭ
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