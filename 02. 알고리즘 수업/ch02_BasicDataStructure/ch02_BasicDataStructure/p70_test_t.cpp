// Q. ������ȯ
// ���
// �� ������ �� �ΰ�?  : 10
// �� �Է� : 12
// �� ������ ��ȯ? : 16
// 10���� 12�� 16���� C�̴�

#include<iostream>
#include<string>

#define ARRSIZE 5

using namespace std;

int main()
{
	int inputStart, inputDest;
	string inputNum;
	cout << "���� �Է� : ";
	cin >> inputStart;
	cout << "�� �Է� : ";
	cin >> inputNum;
	cout << "��ȯ�� ���� �Է� : ";
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
			tempNum = inputNum.back();	// �ƽ�Ű �ڵ�� �޾���
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