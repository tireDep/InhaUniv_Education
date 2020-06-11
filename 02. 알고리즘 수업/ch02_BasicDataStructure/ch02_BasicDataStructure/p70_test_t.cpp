// Q. 진수변환
// 출력
// 몇 진수의 수 인가?  : 10
// 수 입력 : 12
// 몇 진수로 변환? : 16
// 10진수 12는 16진수 C이다

#include<iostream>

using namespace std;

int main()
{
	int notationNum = 0;
	int inputNum = 0;
	int changNotationNum = 0;
	int result[36] = { 0 };

	cout << "몇 진수의 수 인가? : ";
	cin >> notationNum;
	cout << "수 입력 : ";
	cin >> inputNum;
	cout << "몇 진수로 변환할 것인가? : ";
	cin >> changNotationNum;

	int temp = inputNum;
	while (temp != 0)
	{
		if (temp / changNotationNum == 0)
			result[temp % changNotationNum] += 1;
		temp = temp / changNotationNum;
	}
	
	char printChar;
	int check = 1;
	cout << notationNum << "진수 " << inputNum << "는 " << changNotationNum << "진수 ";
	for (int i = 0; i < 36; i++)
	{
		// 65 == A, 90 == Z
		// 10, 11, 12, ...
		if (result[i] != 0)
		{
			check++;
			for (int k = 10; k < 36; k++)
			{
				if (i + 1 == k)
				{
					printChar = 65 + check;
					cout << printChar << "이다" << endl;
				}
			}
		}
	}

	return 0;
}