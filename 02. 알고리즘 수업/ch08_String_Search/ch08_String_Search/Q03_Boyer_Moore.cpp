#include<iostream>
#include<string>

using namespace std;

void BoyerMoore(string &inputString, const string searchString, string &resultString);

int main()
{
	string inputString;
	string searchString;

	cout << "문자열 입력 : ";
	cin >> inputString;

	cout << "검색 문자열 입력 : ";
	cin >> searchString;
	
	string resultString;
	BoyerMoore(inputString, searchString, resultString);

	cout << "\n[결과]\n";
	if (resultString != "")
		cout << resultString << endl;
	else
		cout << "해당 문자열이 존재하지 않음" << endl;

	return 0;
}

void BoyerMoore(string &inputString, const string searchString, string &resultString)
{
	int inputSize = inputString.size();
	int searchSize = searchString.size();
	int i = searchSize - 1;
	int posI;
	int falseCnt = 0;

	while (1)
	{
		if (i >= inputSize)
			break;

		posI = i;
		for (int j = searchSize - 1; j >= 0; j--)
		{
			if (inputString.at(posI) != searchString.at(j))
				falseCnt++;
			else
				posI--;
		}

		if (falseCnt > 0)	// 일치 하지 X 값이 있으면 그 값 만큼 이동
		{
			i += falseCnt;
			falseCnt = 0;
		}
		else if (falseCnt == 0)	// 일치한 문자열을 발견하면 문자열 변경
		{
			string temp;
			for (int i = 0; i<searchSize ; i++)
				temp += "#";
			inputString.replace(posI + 1, searchSize, temp);
			resultString = inputString;

			i += searchSize;	// 해당 문자열만큼 이동후 재탐색
		}	// else i
	}	// while
}	// void BoyerMoore()
