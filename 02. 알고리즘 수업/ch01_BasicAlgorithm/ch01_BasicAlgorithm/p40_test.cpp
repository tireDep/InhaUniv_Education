// Q. ���� �Ƕ�̵�

#include<iostream>

using namespace std;

int main()
{
	int inputNum = 0;
	cout << "���� �Է� : " << endl;
	cin >> inputNum;

	int cnt = 0;
	int check = -1;
	int maxNum = 2 * inputNum - 1;
	for (int i = 0; i < maxNum; i++)
	{
		if (inputNum > cnt && i <= inputNum)
		{
			check++;
			cnt++;
		}
		else
		{
			check--;
			cnt--;
		}

		for (int j = 0; j < maxNum; j++)
		{
			if(i == 0 || i == maxNum - 1)	// ù��, ��������
				cout << cnt << " ";
			else
			{
				if(j>check && j<=maxNum-check)
					cout << cnt << " ";
				else
					cout << " ";
			}
		}
		cout << endl;

	}
	
	return 0;
}