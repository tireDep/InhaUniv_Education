// Q. 1���� 10������ ���� (1+10) * 5�� ���� ������� ���� �� �ֽ��ϴ�.
// ���콺�� �����̶�� �� ����� �̿��Ͽ� 1���� n������ ���� ���� ���ϴ� ���α׷��� �ۼ��ϼ���.

#include<iostream>

using namespace std;

int main()
{
	int inputNum;
	int midNum = 0, result = 0;
	cout << "Case 1" << endl;
	cout << "Input Number : ";
	cin >> inputNum;

	result = (inputNum + 1) * inputNum / 2;
	cout << endl << "Result : " << result << endl;

	int startNum, endNum, temp;
	cout << endl << "Case 2" << endl;
	cout << "Input Number(Start, End) : ";
	cin >> startNum >> endNum;

	if (startNum > endNum)
	{
		temp = startNum;
		startNum = endNum;
		endNum = temp;
	}

	result = (startNum + endNum) * (abs(startNum - endNum) + 1) / 2;
	cout << endl << "Result : " << result << endl;

	return 0;
}