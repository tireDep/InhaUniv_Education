// Q2. API�� ã�Ƽ� Q1�� �Ȱ��� �����غ� ��

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string inputStr;
	cout << "���ڿ� �Է� : ";
	cin >> inputStr;

	string searchStr;
	cout << "�˻� ���ڿ� �Է� : ";
	cin >> searchStr;

	int wordPos = inputStr.find(searchStr);
	if (wordPos == string::npos)	// string::npos : �������� ���� ����� ���� ��
		cout << "�ش� ���ڿ��� �������� ����";
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

		cout << "�Է� ���ڿ� : " << inputStr;
		cout << "��ü ���ڿ� : ";
		cout << resultStr << endl;
	}

	return 0;
}