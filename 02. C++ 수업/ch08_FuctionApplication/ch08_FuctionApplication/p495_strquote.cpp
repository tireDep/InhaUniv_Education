// ��������
// 495p

#include<iostream>
#include<string>

using namespace std;

string Version1(const string &s1, const string &s2);
const string &Version2(string &s1, const string &s2);
const string &Version3(string &s1, const string &s2);

/*
---------------------------------------------
Complie�� O, Warning O,
����� ����
==> ����� ���� ��� Warning Msg �� ������
---------------------------------------------
*/

int main()
{
	string input;
	string copy;
	string result;

	cout << "���ڿ��� �Է��ϼ��� : ";
	getline(cin, input);
	copy = input;
	cout << "�Է��� ���ڿ� : " << input << endl;
	
	result = Version1(copy, "***");
	cout << "\n�ٲ� ���ڿ� : " << result << endl;
	cout << "���� ���ڿ� : " << input << endl;

	result = Version2(copy, "###");
	cout << "\n�ٲ� ���ڿ� : " << result << endl;
	cout << "���� ���ڿ� : " << input << endl;

	result = Version3(copy, "@@@");
	cout << "\n�ٲ� ���ڿ� : " << result << endl;
	cout << "���� ���ڿ� : " << input << endl;
}

string Version1(const string &s1, const string &s2)
{
	string temp;

	temp = s2 + s1 + s2;
	return temp;
}

const string &Version2(string &s1, const string &s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string &Version3(string &s1, const string &s2)	// ���� ����
{
	string temp;

	temp = s2 + s1 + s2;
	return temp;	// �� �̻� �������� �ʴ� �޸�(�ּ�)�� ��ȯ�ϹǷ� ������
}
