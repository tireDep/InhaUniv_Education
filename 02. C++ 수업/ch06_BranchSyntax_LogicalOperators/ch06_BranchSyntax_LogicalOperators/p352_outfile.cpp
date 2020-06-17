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

	cout << "자동차 메이커와 차종을 입력하시오 : ";
	cin.getline(automobile, 50);
	cout << "연식을 입력하시오 : ";
	cin >> year;
	cout << "구입 가격을 입력하시오 : ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	// cout으로 스크린에 정보를 디스플레이
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "메이커와 차종 : " << automobile << endl;
	cout << "연식 : " << year << endl;
	cout << "구입가격 : $" << a_price << endl;
	cout << "현재가격 : $" << d_price << endl << endl;

	// cout대신 outFile을 사용하여 똑같은 일 처리 가능
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "메이커와 차종 : " << automobile << endl;
	outFile << "연식 : " << year << endl;
	outFile << "구입가격 : $" << a_price << endl;
	outFile << "현재가격 : $" << d_price << endl;

	outFile.close();
	return 0;
}