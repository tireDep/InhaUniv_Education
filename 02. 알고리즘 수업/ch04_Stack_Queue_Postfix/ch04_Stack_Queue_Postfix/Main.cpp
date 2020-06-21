#include<iostream>
#include<fstream>
#include<string>

#include"_stack.h"
#include"_Queue.h"

using namespace std;

void ReadFileData(string &readData);
void ReverseData(string &readData);
void PostfixNotation(STACK_S &operatorStack, QUEUE_S &postfixQueue, string &readData);
string NextNumber(int nReadFirst, string &readData, QUEUE_S postfixQueue);


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
	string readData;
	ReadFileData(readData);
	ReverseData(readData);	// ))7+321(*)21+2*4((

	STACK_S operatorStack;	// ������ ����
	QUEUE_S postfixQueue;	// ������
	Initialize(&operatorStack, readData.length());
	Initialize(postfixQueue, readData.length());

	PostfixNotation(operatorStack, postfixQueue, readData);

	// Print(operatorStack);	// �ƹ��͵� ����� ��
	cout << "������ ��ȯ���\n";
	Print(postfixQueue);	// ������

	// -----------------------------------------------------------------------------------
	
	// STACK_S operandStack;
	// Initialize(&operandStack, readData.length());
	
}

string NextNumber(int nReadFirst, string &readData, QUEUE_S postfixQueue)
{
	char temp = nReadFirst;
	string addNum;
	char nextNum;

	if (nReadFirst == minusSign)
		addNum += '-';
	else
		addNum += to_string(temp - '0');

	while (1)
	{
		nextNum = readData.back();
		if (nextNum >= zeroNum && nextNum <= nineNum)
		{
			addNum += to_string(nextNum - '0');
			readData.pop_back();
		}
		else if (nextNum == spotSign)
		{
			addNum += '.';
			readData.pop_back();
		}
		else
			break;
	}

	return addNum;
}

void PostfixNotation(STACK_S &operatorStack, QUEUE_S &postfixQueue, string &readData)
{
	int nReadFirst;	// string���� �о�� ��(�ƽ�Ű����)
	string asciiTemp;	// ���ÿ��� ������ ���� �޾ƿ��� ����
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
				if (asciiTemp == "(")	// )
					break;
				else
					Enque(postfixQueue, asciiTemp);
			}
		}
		else if (nReadFirst >= multiSign && nReadFirst <= divideSign && nReadFirst != errorSign)	// ��ȣ
		{
			int index;
			while (Search(operatorStack, "*", &index) || Search(operatorStack, "/", &index))	// *, /
			{
				if (operatorStack.nextStack - oneNum == index)	// �켱���� ���� ���� �ٷ� �տ� ������ ���
				{
					Pop(&operatorStack, &asciiTemp);
					Enque(postfixQueue, asciiTemp);
				}
				else
					break;
			}
			if (nReadFirst == spotSign)	// �Ҽ���
				Enque(postfixQueue, NextNumber(nReadFirst, readData, postfixQueue));
			else if (nReadFirst == minusSign && readData.back() >= zeroNum && readData.back() <= nineNum)	// ����
				Enque(postfixQueue, NextNumber(nReadFirst, readData, postfixQueue));
			else
				Push(&operatorStack, nReadFirst);
		}

		else if (nReadFirst >= zeroNum && nReadFirst <= nineNum)	// ����
			Enque(postfixQueue, NextNumber(nReadFirst, readData, postfixQueue));
	}
}

void ReadFileData(string &readData)
{
	ifstream fp;
	int readCnt = 0;

	fp.open("calc.txt");

	if (fp.is_open())
	{
		while (!fp.eof())
			getline(fp, readData);
	}
	fp.close();
}

// ���ڿ� ������ -> string.pop_back()
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
