// 352p

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "�ڵ��� ����Ŀ�� ������ �Է��Ͻÿ� : ";
	cin.getline(automobile, 50);
	cout << "������ �Է��Ͻÿ� : ";
	cin >> year;
	cout << "���� ������ �Է��Ͻÿ� : ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	// cout���� ��ũ���� ������ ���÷���
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "����Ŀ�� ���� : " << automobile << endl;
	cout << "���� : " << year << endl;
	cout << "���԰��� : $" << a_price << endl;
	cout << "���簡�� : $" << d_price << endl << endl;

	// cout��� outFile�� ����Ͽ� �Ȱ��� �� ó�� ����
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "����Ŀ�� ���� : " << automobile << endl;
	outFile << "���� : " << year << endl;
	outFile << "���԰��� : $" << a_price << endl;
	outFile << "���簡�� : $" << d_price << endl;

	outFile.close();
	return 0;
}