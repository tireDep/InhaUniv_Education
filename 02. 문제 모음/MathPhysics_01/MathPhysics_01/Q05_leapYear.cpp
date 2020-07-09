// Q. 윤년을 계산하는 프로그램을 작성하라
// 4로 나누어 떨어지면서 100으로는 나누어 떨어지지 않거나, 400으로 나누어 떨어지는 해는 윤년이다.

#include<iostream>

using namespace std;

int main()
{
	int inputYear;

	cout << "년도 입력 : ";
	cin >> inputYear;

	if (inputYear % 4 == 0 && inputYear % 100 != 0)
		cout << "입력한 년도는 윤년입니다." << endl;
	else if (inputYear % 400 == 0)
		cout << "입력한 년도는 윤년입니다." << endl;
	else
		cout << "입력한 년도는 평년입니다." << endl;

	return 0;
}