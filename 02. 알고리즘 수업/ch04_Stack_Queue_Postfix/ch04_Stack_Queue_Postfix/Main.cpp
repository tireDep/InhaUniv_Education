#include<iostream>
#include<fstream>
#include<string>

#include"_stack.h"
#include"_Queue.h"

using namespace std;

void ReadFileData(string &readData);
void ReverseData(string &readData);

enum CALC
{
	rightBracket = 40, leftBracket = 41,
	multiSign = 42, addSign = 43, minusSign = 45, spotSign = 46, divideSign = 47,
	zeroNum = 48, nineNum = 57,

	oneNum = 1,
	errorSign = 44
};

int main()
{
	// 파일 읽어옴
	string readData;
	ReadFileData(readData);

	/* 
	// test

	int test;
	char temp;
	while (readData != "")
	{
		temp = readData.back();
		test = temp - '0';	// ascii -> int
		// or
		// temp = static_cast<int>(readData.back());
		// test = temp - 48;
		cout << test << endl;
		readData.pop_back();
	}
	//test
	*/

	ReverseData(readData);	// ))7+321(*)21+2*4((

	STACK_S operatorStack;	// 연산자 저장
	QUEUE_S postfixQueue;	// 후위식
	Initialize(&operatorStack, readData.length());
	Initialize(postfixQueue, readData.length());

	int nReadFirst;	// string에서 읽어온 값(아스키숫자)
	int asciiTemp;	// 스택에서 제거한 값을 받아오는 변수
	while (readData != "")
	{
		nReadFirst = readData.back();
		readData.pop_back();

		if (nReadFirst == rightBracket)	// (
			Push(&operatorStack, nReadFirst);
		else if (nReadFirst == leftBracket)	// )
		{
			while (1)
			{
				Pop(&operatorStack, &asciiTemp);
				if (asciiTemp == rightBracket)	// )
					break;
				else
					Enque(postfixQueue, asciiTemp);
			}
		}
		else if (nReadFirst >= multiSign && nReadFirst <= divideSign && nReadFirst != errorSign)	// 부호
		{
			int index;
			while (Search(operatorStack, multiSign, &index) || Search(operatorStack, divideSign, &index))	// *, /
			{
				if (operatorStack.nextStack - oneNum == index)	// 우선순위 높은 값이 바로 앞에 존재할 경우
				{
					Pop(&operatorStack, &asciiTemp);
					Enque(postfixQueue, asciiTemp);
				}
				else
					break;
			}
			if (nReadFirst == spotSign)	// 소수점
				Enque(postfixQueue, nReadFirst);
			else if (nReadFirst == minusSign && readData.back() >= zeroNum && readData.back() <= nineNum)	// 음수
				Enque(postfixQueue, nReadFirst);
			else
				Push(&operatorStack, nReadFirst);
		}

		else if (nReadFirst >= zeroNum && nReadFirst <= nineNum)	// 숫자
			Enque(postfixQueue, nReadFirst);
	}

	Print(operatorStack);	// 아무것도 없어야 함
	Print(postfixQueue);	// 후위식

	// STACK_S operandStack;
	
}

void ReadFileData(string &readData)
{
	ifstream fp;
	int readCnt = 0;

	fp.open("calc2.txt");

	if (fp.is_open())
	{
		while (!fp.eof())
			getline(fp, readData);
	}
	fp.close();
}

// 문자열 뒤집기 -> string.pop_back()
void ReverseData(string &readData)
{
	string temp;

	readData = "(" + readData + ")";
	for (int i = readData.length() - 1; i >= 0; i--)
	{
		temp += readData[i];
	}
	temp[temp.length()] = '\0';
	readData = temp;
}
