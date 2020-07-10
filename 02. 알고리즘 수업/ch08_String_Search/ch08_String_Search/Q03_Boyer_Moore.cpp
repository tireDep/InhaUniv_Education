#include<iostream>
#include<string>

using namespace std;

void BoyerMoore(string &inputString, const string searchString, string &resultString);

int main()
{
	string inputString;
	string searchString;

	cout << "���ڿ� �Է� : ";
	cin >> inputString;

	cout << "�˻� ���ڿ� �Է� : ";
	cin >> searchString;
	
	string resultString;
	BoyerMoore(inputString, searchString, resultString);

	cout << "\n[���]\n";
	if (resultString != "")
		cout << resultString << endl;
	else
		cout << "�ش� ���ڿ��� �������� ����" << endl;

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

		if (falseCnt > 0)	// ��ġ ���� X ���� ������ �� �� ��ŭ �̵�
		{
			i += falseCnt;
			falseCnt = 0;
		}
		else if (falseCnt == 0)	// ��ġ�� ���ڿ��� �߰��ϸ� ���ڿ� ����
		{
			string temp;
			for (int i = 0; i<searchSize ; i++)
				temp += "#";
			inputString.replace(posI + 1, searchSize, temp);
			resultString = inputString;

			i += searchSize;	// �ش� ���ڿ���ŭ �̵��� ��Ž��
		}	// else i
	}	// while
}	// void BoyerMoore()
