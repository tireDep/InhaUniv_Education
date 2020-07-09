// Q. ���ڿ����� Ư���� ���ڿ��� ã�� ��, �� ���ڿ��� �ٸ� ���ڷ� ��ü�Ͽ� ���

#include<iostream>
#include<string>

using namespace std;

void Search(string inputStr, string searchStr, int &strCnt, int &index);

int main()
{
	string inputStr;
	cout << "���ڿ� �Է� : ";
	cin >> inputStr;

	string searchStr;
	cout << "�˻� ���ڿ� �Է� : ";
	cin >> searchStr;

	int index = 0;
	int strCnt = 0;
	Search(inputStr, searchStr, strCnt, index);

	if (strCnt == 0)
		cout << "�ش� ���ڿ��� �������� ����\n";
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

		cout << "�Է� ���ڿ� : " << inputStr;
		cout << "��ü ���ڿ� : ";
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