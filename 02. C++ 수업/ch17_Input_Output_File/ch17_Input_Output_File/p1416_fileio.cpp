// ���Ͽ� �����Ѵ�
#include<iostream>	//  �̰��� ���� �ý��ۿ��� �ʿ� x
#include<fstream>
#include<string>

int main()
{
	using namespace std;
	string fileName;

	cout << "�� ������ ���� �̸��� �Է��Ͻʽÿ�. : ";
	cin >> fileName;

	// �� ������ ���� ��� ��Ʈ�� ��ü�� fout �̶�� �̸����� �����Ѵ�
	ofstream fout(fileName.c_str());

	fout << "��� ��ȣ ���⿡ �����Ͻʽÿ�.\n";	// ���Ͽ� ���
	cout << "��� ��ȣ�� �Է��Ͻʽÿ�. : ";	// ȭ�鿡 ���
	float secret;
	cin >> secret;
	fout << "������ ��� ��ȣ�� " << secret << "�Դϴ�.\n";
	fout.close();	// ���� �ݱ�

	// �� ������ ���� �Է� ��Ʈ�� ��ü�� fin�̶�� �̸����� ����
	ifstream fin(fileName.c_str());
	cout << fileName << " ������ ������ ������ �����ϴ�.\n";
	char ch;
	while (fin.get(ch))	// ���Ϸκ��� �� ���ڸ� ����
		cout << ch;	// �� ���ڸ� ȭ�鿡 ���

	cout << "���α׷��� �����մϴ�.\n";
	fin.close();

	return 0;
}