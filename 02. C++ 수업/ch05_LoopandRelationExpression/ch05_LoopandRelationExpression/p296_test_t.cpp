// Q. ���ڿ��� �տ������� ������ �ڿ������� ������ ������ ��츦 Palindrome(ȸ��) �̶�� �Ѵ�.
// ���ڿ��� �Է¹޾� ȸ������ �Ǵ��ϰ� ����� ����ϴ� ���α׷��� �ۼ��϶�.

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string inputStr;
	cout << "���ڿ��� �Է� : ";
	cin >> inputStr;

	int strSize = inputStr.size() - 1;	// null ����
	for (int i = 0; i <= strSize / 2; i++)
	{
		if (inputStr[i] == inputStr[strSize - i])
			continue;
		else
		{
			cout << "\nȸ�� : X\n";
			return 0;
		}
	}

	cout << "\nȸ�� : O\n";


	return 0;
}