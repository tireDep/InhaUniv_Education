#include<iostream>

template <typename T>
T Add(T a, T b)
{
	cout << a + b << endl;
	return 0;
}

template <typename T>
T Swap(T &a, T &b)
{
	T temp;
	
	cout << endl << a << ", " << b << endl;

	temp = a;
	a = b;
	b = temp;

	cout << a << ", " << b << endl;
	return 0;
}

using namespace std;

int main()
{
	int a = 5, b = 7;
	double c = 12.0, d = 4.85;
	
	Add(a, b);
	Add(c, d);
	// Add(a, c); // 작동되지 않음

	Swap(a, b);
	Swap(c, d);
	// Swap(a, c);	// 작동되지 않음
}