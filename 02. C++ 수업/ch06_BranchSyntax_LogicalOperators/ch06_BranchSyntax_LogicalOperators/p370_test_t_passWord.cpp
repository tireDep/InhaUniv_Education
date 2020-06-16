// Q. 게임에서 비밀번호에 어떤 법칙을 요구하는 경우가 있다.
// 다음과 같이 비밀번호를 만들어야 한다고 하자.
// 1. 비밀번호는 적어도 8개의 문자여야 한다.
// 2. 비밀번호는 문자와 숫자로만 구성되어야 한다.
// 3. 비밀번호는 적어도 두 개의 숫자가 포함되어야 한다.
// 사용자가 비밀번호를 입력했을 때 위 법칙에 맞으면
// 'valid password'를, 그렇지 않으면
// 'invaild password'를 출력하는 프로그램을 작성하라.

#include<iostream>
#include<string>

using namespace std;

int main()
{
	char inputPass;
	string passWord;
	int numCnt = 0;
	int charCnt = 0;

	cout << "Input PassWord : ";
	cin.get(inputPass);

	while (1)
	{
		if (inputPass == '\n')
		{
			if ((numCnt + charCnt) >= 8 && numCnt >= 2)
			{
				cout << "\n[Valid PassWord]\n";
				cout << "Your PassWord " << passWord << endl;
			}
			else
				cout << "\n[Invalid PassWord]\n- Count Error\n";
			break;
		}

		if (isdigit(inputPass))
		{
			numCnt++;
			passWord += inputPass;
		}
		else if (isalpha(inputPass))
		{
			charCnt++;
			passWord += inputPass;
		}
		else
		{
			cout << "\n[Invalid PassWord]\n- Wrong Input\n";
			break;
		}
		cin.get(inputPass);
	}

	return 0;
}