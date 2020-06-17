// 세 값의 대소 관계와 중앙값
#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	int midiNum = 0;
	cout << "Input Number A, B, C : ";
	cin >> a >> b >> c;

	if (a >= b)
	{
		if (b >= c)
			midiNum = b;
		else if (a > c)
			midiNum = c;
		else
			midiNum = a;
	}
	else
	{
		if (a > c)
			midiNum = a;
		else if (b > c)
			midiNum = c;
		else
			midiNum = b;
	}
	
	cout << endl << "Midium Number : " << midiNum << endl;

	return 0;
}