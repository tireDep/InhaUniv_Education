#include<iostream>

using namespace std;

int main()
{
	double *p3 = new double [3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1]�� " << p3[1] << "�Դϴ�\n";
	p3 = p3 + 1;
	cout << "\n������ p3[0]�� " << p3[0] << " �̰�, " << "p3[1]�� " << p3[1] << "�Դϴ�.\n";
	// cout << p3[2];
	p3 = p3 - 1;
	delete [] p3;
	
	return 0;
}