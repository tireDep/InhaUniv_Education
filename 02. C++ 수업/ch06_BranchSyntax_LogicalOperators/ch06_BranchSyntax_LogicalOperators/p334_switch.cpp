// 334p

#include<iostream>

using namespace std;

void ShowMenu();
void Report();
void Comfort();

int main()
{
	ShowMenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1: 
			cout << "\a\n";
			break;
		case 2: 
			Report();
			break;
		case 3:
			cout << "������� ���� ȸ�翡 ��̽��ϴ�.\n";
			break;
		case 4:
			Comfort();
			break;
		default:
			cout << "�װ��� ������ �� �����ϴ�.\n";
			break;
		}
		ShowMenu();
		cin >> choice;
	}
	cout << "���α׷��� �����մϴ�!\n";
	
	return 0;
}

void ShowMenu()
{
	cout << "1, 2, 3, 4, 5�� �߿��� �ϳ��� �����Ͻʽÿ�\n";
	cout << "1) ����� 2) ���� 3) �˸����� 4) �ݷ��� 5) ����\n";
}

void Report()
{
	cout << "�̹� �б�� �濵 �Ƿ��� ���� �����ϴ�\n�Ǹŷ��� 120% �þ��, ����� 35% �پ����ϴ�.\n";
}

void Comfort()
{
	cout << "������� ����� ���� �ְ��� CEO��� �����ϰ� �ֽ��ϴ�.\n�̻�ȸ�� ����� ���� �ְ��� CEO��� �����ϰ� �ֽ��ϴ�.\n";
}
