#include <iostream>
#include "cMatrix.h"

using namespace std;

int main()
{
	int input = 0;
	cout << "���� �Է� : ";
	cin >> input;
	cMatrix m1(input);
	m1.Print();

	// cout << "���� �Է� : ";
	// cin >> input;
	// cMatrix m2(input);
	// m2.Print();
	// cout << endl;

	// cMatrix m3 = m1*m2;
	// m3.Print();
	// m3.Identity(5).Print();
	m1.Determinent(0);


	return 0;
}