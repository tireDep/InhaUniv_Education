// Q. �ڸ��� �Ǻ�

#include<iostream>

using namespace std;

int main()
{
	int inputNum = 0;
	int cnt = 0;

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> inputNum;

	while (1)
	{
		cnt++;
		inputNum = inputNum / 10;

		if (inputNum == 0)
			break;
	}
	cout << "\n�ڸ��� : " << cnt << endl;
	
	return 0;
}