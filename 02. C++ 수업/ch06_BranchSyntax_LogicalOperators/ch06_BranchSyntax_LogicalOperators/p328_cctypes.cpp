// 328p

#include<iostream>
#include<cctype>

using namespace std;

int main()
{
	char ch;
	int whiteSpace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cout << "�м��� �ؽ�Ʈ�� �Է��Ͻʽÿ�. �Է��� ���� @�� ǥ���Ͻʽÿ�.\n";
	cin.get(ch);

	while (ch != '@')
	{
		if (isalpha(ch)) // ������
			chars++;
		else if (isspace(ch))	// ȭ��Ʈ �����̽�(����, ���� ��)
			whiteSpace++;
		else if (isdigit(ch))	// ����
			digits++;
		else if (ispunct(ch))	// ������
			punct++;
		else
			others++;

		cin.get(ch);
	}

	cout << endl 
		<< "���ĺ� ���� : " << chars << ", " 
		<< "ȭ��Ʈ �����̽� : " << whiteSpace << ", " 
		<< "���� : " << digits << ", " 
		<< "������ : " << punct << ", " 
		<< "��Ÿ : " << others << endl;

	return 0;

}