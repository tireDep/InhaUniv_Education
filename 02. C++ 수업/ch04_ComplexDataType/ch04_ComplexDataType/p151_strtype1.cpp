#include<iostream>
#include<string>

using namespace std;

int main()
{
	char charArr1[20];
	char charArr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "����̰��� ���� �� ���� �Է��Ͻÿ� : ";
	cin >> charArr1;
	cout << endl << "����̰��� �� �ٸ� ���� �� ���� �Է��Ͻÿ� : ";
	cin >> str1;

	cout << "�Ʒ� �������� ��� ����̰��Դϴ�\n";
	cout << charArr1 << " " << charArr2 << " " << str1 << " " << str2 << endl;
	cout << charArr2 << "���� ����° ���� : " << charArr2[2] << endl;
	cout << str2 << "���� ����° ���� : " << str2[2] << endl;

	return 0;
}