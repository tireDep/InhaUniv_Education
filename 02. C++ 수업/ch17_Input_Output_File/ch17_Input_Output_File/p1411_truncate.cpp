// �Է� ���� �� �� get()�� ����Ͽ� �ڸ���
#include<iostream>

const int SLEN = 10;
inline void eatLine() { while (std::cin.get() != '\n') continue; }

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	char name[SLEN];
	char title[SLEN];

	cout << "�̸��� �Է��Ͻʽÿ�.\n";
	cin.get(name, SLEN);

	if (cin.peek() != '\n')
		cout << "�˼��մϴ�. �̸����� ���Ƽ� " << name << "�� ����־����ϴ�.\n";
	eatLine();

	cout << name << "��! ������ �Է��Ͻʽÿ�.\n";
	cin.get(title, SLEN);
	if (cin.peek() != '\n')
		cout << "������ �� �κ��� �߶����ϴ�.\n";
	eatLine();
	cout << "�̸� : " << name << "\n���� : " << title << endl;

	return 0;
}