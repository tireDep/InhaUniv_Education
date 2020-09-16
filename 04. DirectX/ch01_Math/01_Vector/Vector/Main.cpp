#include <iostream>
#include "cVector.h"

using namespace std;

int main()
{
	cVector3 temp;
	cVector3 uVec(1,-1,0);
	cVector3 vVec(3,2,1);

	if (uVec == vVec)
		cout << "�� ���� �� : " << "�� ���Ͱ� ����" << endl << endl;
	else
		cout << "�� ���� �� : " << "�� ���Ͱ� ���� x" << endl << endl;
	// >> ���� ��

	temp = uVec + vVec;
	cout <<"Vector + : ";
	temp.PrintValue();
	cout << endl;
	// >> ���� ����

	cout << "Dot Product : " << uVec.Dot(uVec, vVec) << endl << endl;
	// >> ���� ����

	temp = uVec.Cross(uVec, vVec);
	cout << "Cross Product : ";
	temp.PrintValue();
	cout << endl;
	// >> ���� ����
}