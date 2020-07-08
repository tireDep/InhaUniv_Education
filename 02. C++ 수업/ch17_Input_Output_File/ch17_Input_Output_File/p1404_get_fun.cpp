// get(), getline() ���
// getline() : �Է� ��Ʈ���� �ִ� ���� ������ �а� ����
// get() : �״�� ���� ��
#include<iostream>

const int Limit = 255;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char input[Limit];

	cout << "getline()�� ó���� ���ڿ��� �Է��Ͻʽÿ�.\n";
	cin.getline(input, Limit, '#');
	cout << "������ ���� �Է��ϼ̽��ϴ�.\n";
	cout << input << "\n1�ܰ� �Ϸ�\n";

	char ch;
	cin.get(ch);
	cout << "���� �Է� ���ڴ� " << ch << "�Դϴ�.\n";

	if (ch != '\n')
		cin.ignore(Limit, '\n');	// �� ���� �������� �а� ������

	cout << "get()�� ó���� ���ڿ��� �Է��Ͻʽÿ�.\n";
	cin.get(input, Limit, '#');
	cout << "������ ���� �Է��ϼ̽��ϴ�.\n";
	cout << input << "\n2�ܰ� �Ϸ�\n";

	cin.get(ch);
	cout << "���� �Է� ���ڴ� " << ch << "�Դϴ�" << endl;

	return 0;
}