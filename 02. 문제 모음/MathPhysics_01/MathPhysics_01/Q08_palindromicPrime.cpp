// Q. 회문소수(Palindromic prime) : 거꾸로 읽어도 자기 자신이 되는 소수를 찾아 출력하시오
// 2~1000사이
// ex) 2, 3, 5, 7, 11, 101, ...

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int check = 0;
	int tmp = 0;
	string checkStr;

	for (int i = 2; i <= 1000; i++)
	{
		check = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				check++;
		}
		
		if (check == 2)
		{
			checkStr = to_string(i);
			if (checkStr.front() == checkStr.back())
				cout << checkStr << " ";
		}
	}
	return 0;
}
