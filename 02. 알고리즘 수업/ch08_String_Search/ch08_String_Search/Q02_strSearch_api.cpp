// Q2. API를 찾아서 Q1과 똑같이 구현해볼 것

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string inputStr;
	cout << "문자열 입력 : ";
	cin >> inputStr;

	string searchStr;
	cout << "검색 문자열 입력 : ";
	cin >> searchStr;

	int wordPos = inputStr.find(searchStr);
	if (wordPos == string::npos)	// string::npos : 존재하지 않을 경우의 리턴 값
		cout << "해당 문자열이 존재하지 않음";
	else
	{
		string resultStr = inputStr;
		string temp;
		while (1)
		{
			temp = "\0";
			for (int i = 0; i<searchStr.size(); i++)
				temp += "#";
			resultStr.replace(wordPos, searchStr.size(), temp);

			wordPos = resultStr.find(searchStr);
			if (wordPos == string::npos)
				break;
		}

		cout << "입력 문자열 : " << inputStr;
		cout << "대체 문자열 : ";
		cout << resultStr << endl;
	}

	return 0;
}