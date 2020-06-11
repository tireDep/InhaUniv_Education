#include<iostream>

using namespace std;

int main()
{
	double *p3 = new double [3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1]은 " << p3[1] << "입니다\n";
	p3 = p3 + 1;
	cout << "\n이제는 p3[0]이 " << p3[0] << " 이고, " << "p3[1]이 " << p3[1] << "입니다.\n";
	// cout << p3[2];
	p3 = p3 - 1;
	delete [] p3;
	
	return 0;
}