// Q. ������ȯ
// ���
// �� ������ �� �ΰ�?  : 10
// �� �Է� : 12
// �� ������ ��ȯ? : 16
// 10���� 12�� 16���� C�̴�

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void InputNumber(int *startNum, int *endNum, string *strInputNum);
void ChangeDecimal(int startNum, int *totalNum, string *tempStrInputNum);
void ChangeAlpha(int start, int end, int tempNum, int *totalNum, int startNum, int powNum);
void Conversion(int startNum, int endNum, int totalNum, string *strChangeNum);

int main()
{
	int startNum, endNum;
	string strInputNum;
	InputNumber(&startNum, &endNum, &strInputNum);

	int totalNum = 0;
	string tempStrInputNum = strInputNum;
	ChangeDecimal(startNum, &totalNum, &tempStrInputNum);

	string strChangeNum;
	Conversion(startNum, endNum, totalNum, &strChangeNum);

	if (endNum == 10)
		cout << endl << startNum << "���� " << strInputNum << "�� " << endNum << "���� " << totalNum << "�̴�" << endl;
	else if (startNum == endNum)
		cout << endl << startNum << "���� " << strInputNum << "�� " << endNum << "���� " << strInputNum << "�̴�" << endl;
	else
		cout << endl << startNum << "���� " << strInputNum << "�� " << endNum << "���� " << strChangeNum << "�̴�" << endl;

	return 0;
}

void InputNumber(int *startNum, int *endNum, string *strInputNum)
{
	cout << "���� �Է� : ";
	cin >> *startNum;
	cout << "�� �Է� : ";
	cin >> *strInputNum;
	cout << "��ȯ�� ���� �Է� : ";
	cin >> *endNum;
}

void ChangeDecimal(int startNum, int *totalNum, string *tempStrInputNum)
{
	int tempNum = 0;
	int addNum = 0;
	int powNum = -1;

	while (*tempStrInputNum != "")
	{
		powNum++;

		if (startNum != 10)
		{
			tempNum = tempStrInputNum->back();	// �ƽ�Ű �ڵ� ��
			tempStrInputNum->pop_back();
		}
		else
		{
			*totalNum = atoi(tempStrInputNum->c_str());
			return;
		}

		if (tempNum >= 48 && tempNum <= 57)
		{
			addNum = 0;
			for (int i = 48; i <= 57; i++)
			{
				if (tempNum == i)
				{
					*totalNum += addNum * pow(startNum, powNum);
				}
				addNum++;
			}
		}
		else
		{
			if (tempNum >= 65 && tempNum <= 90)
				ChangeAlpha(65, 90, tempNum, totalNum, startNum, powNum);
			else if (tempNum >= 97 && tempNum <= 122)
				ChangeAlpha(97, 122, tempNum, totalNum, startNum, powNum);
			else
			{
				cout << "\n�߸��� �� �Է����� ����" << endl;
				exit(1);
			}
		}
	}
}

void ChangeAlpha(int start, int end, int tempNum, int *totalNum, int startNum, int powNum)
{
	int alphaNum = 10;
	for (int i = start; i <= end; i++)
	{
		if (tempNum == i)
		{
			*totalNum += alphaNum * pow(startNum, powNum);
		}
		alphaNum++;
	}
}

void Conversion(int startNum, int endNum, int totalNum, string *strChangeNum)
{
	int tempChangeNum = 0;
	string strTempChange;
	string alphaSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (totalNum != 0)
	{
		if (startNum == endNum)
			break;

		// if (startNum > endNum)	// ū ���� -> ���� ����
		// 	tempChangeNum = totalNum / endNum;
		// else
		// 	tempChangeNum = totalNum % endNum;

		tempChangeNum = totalNum % endNum;

		if (tempChangeNum < endNum && tempChangeNum < 10)
			strTempChange += to_string(tempChangeNum);
		else
		{
			for (int i = 0; i < 26; i++)
			{
				if (10 + i == tempChangeNum)	// ���ĺ� ��
					strTempChange += alphaSet[i];
			}
		}
		totalNum = totalNum / endNum;
	}

	while (strTempChange != "")
	{
		*strChangeNum += strTempChange.back();
		strTempChange.pop_back();
	}
}