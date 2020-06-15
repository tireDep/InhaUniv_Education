// Q. 진수변환
// 출력
// 몇 진수의 수 인가?  : 10
// 수 입력 : 12
// 몇 진수로 변환? : 16
// 10진수 12는 16진수 C이다

#include<iostream>
#include<string>

#define ARRSIZE 5

using namespace std;

int main()
{
	int inputStart, inputDest;
	string inputNum;
	cout << "진수 입력 : ";
	cin >> inputStart;
	cout << "수 입력 : ";
	cin >> inputNum;
	cout << "변환할 진수 입력 : ";
	cin >> inputDest;

	int tempNum = 0;
	int changeNum = 0;
	int index = 0;
	// int *saveNum = new int[ARRSIZE]();
	string saveNum;

	while (inputNum != "")
	{
		if (inputStart != 10)
		{
			tempNum = inputNum.back();	// 아스키 코드로 받아짐
			inputNum.pop_back();
		}

		changeNum = 0;
		if (tempNum >= 48 && tempNum <= 57)
		{
			for (int i = 48; i <= 57; i++)
			{
				if (tempNum == i)
				{
					saveNum += to_string(changeNum);
					index++;
				}
				changeNum++;
			}
		}
		else if (tempNum >= 65 && tempNum <= 90)
		{
			for (int i = 65; i <= 90; i++)
			{
				if (tempNum == i)
				{
					saveNum += tempNum;
					index++;
				}
				changeNum++;
			}
		}
	}

	for (int i = ARRSIZE - 1; i >= 0; i--)
	{
		cout << saveNum[i] << " ";
	}

	// delete[] saveNum;
}