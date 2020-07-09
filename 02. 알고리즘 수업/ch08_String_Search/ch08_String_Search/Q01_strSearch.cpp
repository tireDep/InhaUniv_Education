// Q. 문자열에서 특정한 문자열을 찾은 후, 이 문자열을 다른 문자로 대체하여 출력

#include<iostream>
#include<string>

using namespace std;

void Search(string inputStr, string searchStr, int &strCnt, int &index);

int main()
{
	string inputStr;
	cout << "문자열 입력 : ";
	cin >> inputStr;

	string searchStr;
	cout << "검색 문자열 입력 : ";
	cin >> searchStr;

	int index = 0;
	int strCnt = 0;
	Search(inputStr, searchStr, strCnt, index);

	if (strCnt == 0)
		cout << "해당 문자열이 존재하지 않음\n";
	else
	{	
		string resultStr = resultStr;
		while (1)
		{
			for (int i = 0; i < inputStr.size(); i++)
			{
				if (i >= index && i < index + searchStr.size())
					resultStr += "#";
				else
					resultStr += inputStr[i];
			}

			Search(resultStr, searchStr, strCnt, index);
			if (strCnt == 0)
				break;
		}

		cout << "입력 문자열 : " << inputStr;
		cout << "대체 문자열 : ";
		cout << resultStr << endl;
	}

	return 0;
}

void Search(string inputStr, string searchStr, int &strCnt, int &index)
{
	int i = 0, j = 0;
	while (1)
	{
		if (strCnt == searchStr.size() || i == inputStr.size())
			break;

		if (searchStr[j] == inputStr[i])
		{
			if (j == 0)
				index = i;
			strCnt++;
			j++;
		}
		else
		{
			j = 0;
			strCnt = 0;
		}
		i++;
	}
}