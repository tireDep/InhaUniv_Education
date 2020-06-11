// Q. 자릿수 판별

#include<iostream>

using namespace std;

int main()
{
	int inputNum = 0;
	int cnt = 0;

	cout << "숫자를 입력하세요 : ";
	cin >> inputNum;

	while (1)
	{
		cnt++;
		inputNum = inputNum / 10;

		if (inputNum == 0)
			break;
	}
	cout << "\n자릿수 : " << cnt << endl;
	
	return 0;
}