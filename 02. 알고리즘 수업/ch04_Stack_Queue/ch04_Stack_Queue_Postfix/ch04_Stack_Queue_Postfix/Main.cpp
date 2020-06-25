#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

#include"_stack.h"
#include"_Queue.h"

using namespace std;

void ReadFileData(string &readData);
void ReverseData(string &readData);

void PostfixNotation(STACK_S &operatorStack, QUEUE_S &postfixQueue, string &readData);
string NextNumber(int nReadFirst, string &readData, QUEUE_S postfixQueue);
void PopEnquePush(STACK_S operatorStack, QUEUE_S &postfixQueue, string asciiTemp, int nReadFirst);

void Calculator(QUEUE_S &postfixQueue, STACK_S &operandStack);
void CalcVal(STACK_S *operandStack, char sign);

enum CALC
{
	rightBracket = 40, leftBracket = 41,
	multiSign = 42, addSign = 43, minusSign = 45, spotSign = 46, divideSign = 47,
	zeroNum = 48, nineNum = 57,

	errorSign = 44
};

int main()
{
	string readData;
	ReadFileData(readData);
	cout << "������\n" << readData << endl << endl;
	ReverseData(readData);

	STACK_S operatorStack;	// ������ ����
	QUEUE_S postfixQueue;	// ������
	STACK_S operandStack;	// ���
	Initialize(&operatorStack, readData.length());
	Initialize(postfixQueue, readData.length());
	Initialize(&operandStack, readData.length());

	PostfixNotation(operatorStack, postfixQueue, readData);

	cout << "������ ��ȯ\n";
	Print(postfixQueue);
	
	Calculator(postfixQueue, operandStack);
	
	string print;
	Pop(&operandStack, &print);
	cout << "\n��� ���\n" << print << endl;
	
	Terminate(&operatorStack);
	Terminate(&operandStack);
	Terminate(postfixQueue);

	return 0;
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

void PostfixNotation(STACK_S &operatorStack, QUEUE_S &postfixQueue, string &readData)
{
	bool isSign = true;	// ���� Ȯ��
	int nReadFirst;	// string���� �о�� ��(�ƽ�Ű����)	// char�� �ص� ���ư�
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
			if (nReadFirst == spotSign)	// �Ҽ���
				Enque(postfixQueue, NextNumber(nReadFirst, readData, postfixQueue));
			else if (nReadFirst == minusSign && isSign == true 
				|| readData.back() < multiSign && readData.back() > divideSign)	// ����
			{
				isSign = false;
				Enque(postfixQueue, NextNumber(nReadFirst, readData, postfixQueue));
			}
			else
			{
				isSign = true;
				if (operatorStack.value[operatorStack.nextStack - 1] == "/" 
					|| operatorStack.value[operatorStack.nextStack - 1] == "*")	// �켱���� ���� ���� �ٷ� �տ� ������ ���
					PopEnquePush(operatorStack, postfixQueue, asciiTemp, nReadFirst);
				else if (operatorStack.value[operatorStack.nextStack - 1] == "+" 
					|| operatorStack.value[operatorStack.nextStack - 1] == "-")
				{
					if (nReadFirst != multiSign && nReadFirst != divideSign)	// ���� ��ȣ�� ������ �� �켱������ ���� ���
						PopEnquePush(operatorStack,postfixQueue,asciiTemp,nReadFirst);
					else
						Push(&operatorStack, nReadFirst);	// ���� ��ȣ�� ������ �� �켱������ ���� ���
				}
				else
					Push(&operatorStack, nReadFirst);	// ������ ��� ����
			}
		}

		else if (nReadFirst >= zeroNum && nReadFirst <= nineNum)	// ����
		{
			isSign = false; 
			Enque(postfixQueue, NextNumber(nReadFirst, readData, postfixQueue));
		}
	}
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

void PopEnquePush(STACK_S operatorStack, QUEUE_S &postfixQueue, string asciiTemp, int nReadFirst)
{
	Pop(&operatorStack, &asciiTemp);
	Enque(postfixQueue, asciiTemp);
	Push(&operatorStack, nReadFirst);
}

void Calculator(QUEUE_S &postfixQueue, STACK_S &operandStack)
{
	string dequeData;

	cout << endl;
	while (postfixQueue.cnt != 0)
	{
		Deque(postfixQueue, dequeData);

		if (dequeData == "+") 
			CalcVal(&operandStack,'+');
		else if (dequeData == "-")
			CalcVal(&operandStack, '-');
		else if (dequeData == "*")
			CalcVal(&operandStack, '*');
		else if (dequeData == "/")
			CalcVal(&operandStack, '/');
		else
			Push(&operandStack, dequeData);
	}
}

void CalcVal(STACK_S *operandStack, char sign)
{
	string fNum, sNum;
	double result = 0;

	Pop(operandStack, &fNum);
	Pop(operandStack, &sNum);

	switch (sign)
	{
	case '+':
		result = atof(sNum.c_str()) + atof(fNum.c_str());
		break;
	case '-':
		result = atof(sNum.c_str()) - atof(fNum.c_str());
		break;
	case '*':
		result = atof(sNum.c_str()) * atof(fNum.c_str());
		break;
	case '/':
		result = atof(sNum.c_str()) / atof(fNum.c_str());
		break;
	default:
		break;
	}

	Push(operandStack, to_string(result));
}