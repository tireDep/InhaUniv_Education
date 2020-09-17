#include <iostream>
#include "cMatrix.h"

using namespace std;

int main()
{
	int input = 0;
	cout << "차수 입력 : ";
	cin >> input;
	cMatrix m1(input);
	m1.Print();

	cMatrix m3(input);
	m3.SetZero();

	float detNum = m1.Determinent();
	m3 = m1.Inverse(detNum);

	(m3*m1).Print();

	return 0;
}