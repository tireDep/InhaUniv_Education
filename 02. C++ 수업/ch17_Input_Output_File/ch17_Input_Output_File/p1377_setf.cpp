// setf() : ��� ���� ������ ������
#include<iostream>

int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	int temperature = 63;

	cout << "������ ���� : ";
	cout.setf(ios_base::showpos);
	cout << temperature << endl;	// �÷��� ��ȣ ���

	cout << "���α׷��ӵ鿡�� �� ����\n";
	cout << std::hex << temperature << endl;	// ��¿� 16�� ���
	cout.setf(ios_base::uppercase);				// 16�� ��¿� �빮�� ���
	cout.setf(ios_base::showbase);				// 16�� ��¿� OX ���
	cout << "�Ǵ�\n";
	cout << temperature << endl;

	cout << true << "!�� ���� ";
	cout.setf(ios_base::boolalpha);
	cout << true << "�̴�.\n";

	return 0;
}