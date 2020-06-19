// 542p

#include<iostream>

template <typename T>
T Lesser(T a, T b)	// #1
{
	return a < b ? a : b;
}

int Lesser(int a, int b) // #2
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}

using namespace std;

int main()
{
	int m = 20, n = -30;
	double x = 15.5, y = 25.9;
	
	cout << Lesser(m, n) << endl;	// #2
	cout << Lesser(x, y) << endl;	// double, #1
	cout << Lesser<>(m, n) << endl;	// int, #1
	cout << Lesser<int>(x, y) << endl;	// int, #1
}