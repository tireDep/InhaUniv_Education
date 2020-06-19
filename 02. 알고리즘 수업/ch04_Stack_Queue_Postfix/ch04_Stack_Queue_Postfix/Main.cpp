#include<iostream>
#include<fstream>
#include<string>

#include"_stack.h"
#include"_Queue.h"

using namespace std;

void ReverseData(string &readData);

int main()
{
	// 파일 읽어옴
	ifstream fp;
	string readData;
	int readCnt = 0;

	fp.open("calc2.txt");

	if (fp.is_open())
	{
		while (!fp.eof())
			getline(fp, readData);
	}
	fp.close();

	/* 
	// test
	readData = "(" + readData + ")\n\n";
	cout << readData << ", " << readData.size() << ", " << readData.length();

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

	// cout << endl << readData;
	ReverseData(readData);
	// cout << endl << readData;

	STACK_S operatorStack;
	STACK_S operandStack;
	QUEUE_S postfixQueue;	// 후위식
	
}

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

/*
음수 주의
*/