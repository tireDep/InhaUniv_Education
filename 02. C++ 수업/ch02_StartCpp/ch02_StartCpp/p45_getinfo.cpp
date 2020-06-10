#include<iostream>

using namespace std;

int main()
{
	int carrots;

	cout << "당근을 몇 개나 가지고 있니?" << endl;
	cin >> carrots;
	carrots += 2;
	cout << "여기 두개가 더 있다." << "이제 당근은 모두 " << carrots << "개 이다." << endl;

	return 0;
}