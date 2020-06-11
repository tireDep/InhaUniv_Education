// Q. ������ȯ
// ���
// �� ������ �� �ΰ�?  : 10
// �� �Է� : 12
// �� ������ ��ȯ? : 16
// 10���� 12�� 16���� C�̴�

#include<iostream>

using namespace std;

int main()
{
	int notationNum = 0;
	int inputNum = 0;
	int changNotationNum = 0;
	int result[36] = { 0 };

	cout << "�� ������ �� �ΰ�? : ";
	cin >> notationNum;
	cout << "�� �Է� : ";
	cin >> inputNum;
	cout << "�� ������ ��ȯ�� ���ΰ�? : ";
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
	cout << notationNum << "���� " << inputNum << "�� " << changNotationNum << "���� ";
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
					cout << printChar << "�̴�" << endl;
				}
			}
		}
	}

	return 0;
}