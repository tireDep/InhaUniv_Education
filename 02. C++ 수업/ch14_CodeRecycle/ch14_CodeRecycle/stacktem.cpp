#include<iostream>
#include<string>
#include<cctype>
#include"stacktp.h"

using std::cin;
using std::cout;

int main()
{
	Stack<std::string> st;
	char ch;
	std::string po;

	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;

		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'B':
		case 'a':
		case 'b':
			cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�.\n";
			cin >> po;
			if (st.IsFull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.Push(po);
			break;

		case 'P':
		case 'p':
			if (st.IsEmtpy())
				cout << "������ ��� �ֽ��ϴ�.\n";
			else
			{
				st.Pop(po);
				cout << "#" << po << "�ֹ����� ó���߽��ϴ�.\n";
			}
			break;
		}
		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "���α׷��� �����մϴ�.\n";
	
	return 0;
}