// ���Ͽ� ������ ������
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

const char *file = "quests.txt";

int main()
{
	using namespace std;
	char ch;

	ifstream fin;
	fin.open(file);

	// �ʱ� ������ ȭ�鿡 ǥ����
	if (fin.is_open())
	{
		cout << file << " ������ ���� ������ ������ �����ϴ�.\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	// ���ο� �մ� �̸����� �߰���
	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "����� ���� " << file << " ������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}

	cout << "���ο� �մ� �̸����� �Է��Ͻʽÿ�.(�������� �� �� �Է�) : ";
	string name;
	while (getline(cin, name) && name.size() > 0)
		fout << name << endl;
	fout.close();

	// ������ ������ ȭ�鿡 ǥ��
	fin.clear();	// � �����Ϸ��� �̰��� �䱸���� x
	fin.open(file);
	if (fin.is_open())
	{
		cout << file << " ������ ������ ������ ������ �����ϴ�.\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	cout << "���α׷��� �����մϴ�.\n";
	
	return 0;
}