// Q. 1부터 10까지의 합은 (1+10) * 5와 같은 방법으로 구할 수 있습니다.
// 가우스의 덧셈이라는 이 방법을 이용하여 1부터 n까지의 정수 합을 구하는 프로그램을 작성하세요.

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