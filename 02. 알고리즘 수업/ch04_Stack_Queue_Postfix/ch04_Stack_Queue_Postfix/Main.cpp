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
	cout << "중위식\n" << readData << endl << endl;
	ReverseData(readData);

	STACK_S operatorStack;	// 연산자 저장
	QUEUE_S postfixQueue;	// 후위식
	STACK_S operandStack;	// 계산
	Initialize(&operatorStack, readData.length());
	Initialize(postfixQueue, readData.length());
	Initialize(&operandStack, readData.length());

	PostfixNotation(operatorStack, postfixQueue, readData);

	cout << "후위식 변환\n";
	Print(postfixQueue);
	
	Calculator(postfixQueue, operandStack);
	
	string print;
	Pop(&operandStack, &print);
	cout << "\n계산 결과\n" << print << endl;
	
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

void PostfixNotation(STACK_S &operatorStack, QUEUE_S &postfixQueue, string &readData)
{
	bool isSign = true;	// 음수 확인
	int nReadFirst;	// string에서 읽어온 값(아스키숫자)	// char로 해도 돌아감
	string asciiTemp;	// 스택에서 제거한 값을 받아오는 변수
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
		else if (nReadFirst >= multiSign && nReadFirst <= divideSign && nReadFirst != errorSign)	// 부호
		{
			if (nReadFirst == spotSign)	// 소수점
				Enque(postfixQueue, NextNumber(nReadFirst, readData, postfixQueue));
			else if (nReadFirst == minusSign && isSign == true 
				|| readData.back() < multiSign && readData.back() > divideSign)	// 음수
			{
				isSign = false;
				Enque(postfixQueue, NextNumber(nReadFirst, readData, postfixQueue));
			}
			else
			{
				isSign = true;
				if (operatorStack.value[operatorStack.nextStack - 1] == "/" 
					|| operatorStack.value[operatorStack.nextStack - 1] == "*")	// 우선순위 높은 값이 바로 앞에 존재할 경우
					PopEnquePush(operatorStack, postfixQueue, asciiTemp, nReadFirst);
				else if (operatorStack.value[operatorStack.nextStack - 1] == "+" 
					|| operatorStack.value[operatorStack.nextStack - 1] == "-")
				{
					if (nReadFirst != multiSign && nReadFirst != divideSign)	// 직전 부호와 비교했을 때 우선순위가 같은 경우
						PopEnquePush(operatorStack,postfixQueue,asciiTemp,nReadFirst);
					else
						Push(&operatorStack, nReadFirst);	// 직전 부호와 비교했을 때 우선순위가 높은 경우
				}
				else
					Push(&operatorStack, nReadFirst);	// 스택이 비어 있음
			}
		}

		else if (nReadFirst >= zeroNum && nReadFirst <= nineNum)	// 숫자
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