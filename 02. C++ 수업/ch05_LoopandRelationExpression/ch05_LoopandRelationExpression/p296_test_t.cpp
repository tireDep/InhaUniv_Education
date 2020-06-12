// Q. 문자열을 앞에서부터 읽으나 뒤에서부터 읽으나 동일한 경우를 Palindrome(회문) 이라고 한다.
// 문자열을 입력받아 회문인지 판단하고 결과를 출력하는 프로그램을 작성하라.

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string inputStr;
	cout << "문자열을 입력 : ";
	cin >> inputStr;

	int strSize = inputStr.size() - 1;	// null 제거
	for (int i = 0; i <= strSize / 2; i++)
	{
		if (inputStr[i] == inputStr[strSize - i])
			continue;
		else
		{
			cout << "\n회문 : X\n";
			return 0;
		}
	}

	cout << "\n회문 : O\n";


	return 0;
}