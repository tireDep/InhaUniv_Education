#include<iostream>

using namespace std;

int main()
{
	const int arSize = 20;
	char name[arSize];
	char dessert[arSize];

	cout << "�̸��� �Է��ϼ��� : ";
	cin.getline(name, arSize);
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ� : ";
	cin.getline(dessert, arSize);

	cout << "���ִ� " << dessert << " ����Ʈ�� �غ��߽��ϴ�. " << name << "��!" << endl;

	return 0;
}