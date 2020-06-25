#include<iostream>
#include"MyTime0.h"

int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	// total = coding.Sum(fixing);
	total = coding + fixing;	// 연산자 오버로딩
	cout << "coding.sum(fixing) = ";
	total.Show();

	// 연산자 오버로딩 test
	cout << endl << endl << "- : ";
	total = coding - fixing;
	total.Show();

	cout << endl << "* : ";
	total = coding * 3;
	total.Show();
	
	cout << endl << "/ : ";
	total = fixing / 4;
	total.Show();

	cout << endl;

	return 0;
}