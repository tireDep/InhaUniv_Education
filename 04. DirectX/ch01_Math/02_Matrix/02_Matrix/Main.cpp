#include <iostream>
#include "cMatrix.h"

using namespace std;

int main()
{
	// int input = 0;
	// cout << "���� �Է� : ";
	// cin >> input;
	// cMatrix m1(input);
	// m1.Print();
	// 
	// cMatrix m3(input);
	// m3.SetZero();
	// 
	// float detNum = m1.Determinent();
	// m3 = m1.Inverse(detNum);
	// 
	// (m3*m1).Print();
	// 
	// return 0;

	int input = 0;
	cout << "���� �Է� : ";
	cin >> input;
	cMatrix m1(input);
	m1.SetVal();

	cout << "Determinant : " << endl;
	cout << m1.Determinent() << endl;

	cout << "Adjoint : " << endl;
	m1.Adjoint().Print();

	float fDet = m1.Determinent();
	cMatrix invMat = m1.Inverse(fDet);
	cout << "����� : \n";
	invMat.Print();

	cout << "����� Ȯ�� : " << endl;
	(invMat * m1).Print();
}