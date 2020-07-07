#include<iostream>
#include<string>

int main()
{
	using namespace std;

	string one("Lottery Winnder!");	// ctor #1
	cout << one << endl;	// overloading <<

	string two(20, '$');	// ctor #2
	cout << two << endl;

	string three(one);	// ctor #3
	cout << three << endl;
	one += " Oops!";	// overloading +=
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';

	string four;	// ctor #4
	four = two + three;	// overloading +, =
	cout << four << endl;

	char alls[] = "All's well that end well";
	string five(alls, 20);	// ctor #5
	cout << five << endl;

	string six(alls + 6, alls + 10);	// ctor #6
	cout << six << ", ";

	string seven(&five[6], &five[10]);	// ctor #6
	cout << seven << "...\n";

	string eight(four, 7, 16);	// ctor #7
	cout << eight << "in motion!" << endl;

	return 0;
}