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
	// ���� �о��
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

	STACK_S operatorStack;	// ������ ����
	QUEUE_S postfixQueue;	// ������
	Initialize(&operatorStack, readData.length());
	Initialize(postfixQueue, readData.length());

	int nReadFirst;	// string���� �о�� ��(�ƽ�Ű����)
	int asciiTemp;	// ���ÿ��� ������ ���� �޾ƿ��� ����
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
		else if (nReadFirst >= multiSign && nReadFirst <= divideSign && nReadFirst != errorSign)	// ��ȣ
		{
			int index;
			while (Search(operatorStack, multiSign, &index) || Search(operatorStack, divideSign, &index))	// *, /
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
				Enque(postfixQueue, nReadFirst);
			else if (nReadFirst == minusSign && readData.back() >= zeroNum && readData.back() <= nineNum)	// ����
				Enque(postfixQueue, nReadFirst);
			else
				Push(&operatorStack, nReadFirst);
		}

		else if (nReadFirst >= zeroNum && nReadFirst <= nineNum)	// ����
			Enque(postfixQueue, nReadFirst);
	}

	Print(operatorStack);	// �ƹ��͵� ����� ��
	Print(postfixQueue);	// ������

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
