// 69p 05
#include<iostream>

using namespace std;

int main()
{
	double temperature;
	cout << "¼·¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ°í Enter Å°¸¦ ´©¸£½Ê½Ã¿À : ";
	cin >> temperature;
	cout << "¼·¾¾ " << temperature << "µµ´Â È­¾¾·Î " << temperature * 1.8 + 32 << "µµ ÀÔ´Ï´Ù." << endl;

	return 0;
}