// Q. ���ӿ��� ��й�ȣ�� � ��Ģ�� �䱸�ϴ� ��찡 �ִ�.
// ������ ���� ��й�ȣ�� ������ �Ѵٰ� ����.
// 1. ��й�ȣ�� ��� 8���� ���ڿ��� �Ѵ�.
// 2. ��й�ȣ�� ���ڿ� ���ڷθ� �����Ǿ�� �Ѵ�.
// 3. ��й�ȣ�� ��� �� ���� ���ڰ� ���ԵǾ�� �Ѵ�.
// ����ڰ� ��й�ȣ�� �Է����� �� �� ��Ģ�� ������
// 'valid password'��, �׷��� ������
// 'invaild password'�� ����ϴ� ���α׷��� �ۼ��϶�.

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