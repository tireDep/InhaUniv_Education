// 441p

#include<iostream>
#include<conio.h>

using namespace std;

const int Len = 66;
const int Divs = 6;

void SubDivide(char ar[], int low, int high, int level);

int main()
{
	char ruler[Len];
	for (int i = 0; i < Len - 2; i++)
		ruler[i] = ' ';

	ruler[Len - 1] = '\0';

	int max = Len - 2;
	int min = 0;

	ruler[min] = ruler[max] = '|';
	_getch();
	cout << ruler << endl;

	for (int i = 0; i <= Divs; i++)
	{
		SubDivide(ruler, min, max, i);
		_getch();
		cout << ruler << endl;
		for (int j = 1; j < Len - 2; j++)
			ruler[j] = ' ';
	}

	return 0;
}

void SubDivide(char ar[], int low, int high, int level)
{
	if (0 == level)
		return;

	int mid = (high + low) / 2;
	ar[mid] = '|';
	SubDivide(ar, low, mid, level - 1);
	SubDivide(ar, mid, high, level - 1);
}