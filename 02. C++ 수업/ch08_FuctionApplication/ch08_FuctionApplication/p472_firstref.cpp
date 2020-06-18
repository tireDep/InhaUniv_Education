// 참조변수
// 472p

#include<iostream>

using namespace std;

int main()
{
	int rats = 101;
	int & rodents = rats;	

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats의 주소 = " << &rats;
	cout << ", rodents의 주소 = " << &rodents << endl;

	return 0;
}

/*
-----------------------------------------------------
int & rodents = rats 는 
본질적으로 int * const pr = &rats 와 같은 역할
-----------------------------------------------------
*/