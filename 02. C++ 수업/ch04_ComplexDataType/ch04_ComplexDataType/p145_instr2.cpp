#include<iostream>

using namespace std;

int main()
{
	const int arSize = 20;
	char name[arSize];
	char dessert[arSize];

	cout << "이름을 입력하세요 : ";
	cin.getline(name, arSize);
	cout << "좋아하는 디저트를 입력하십시오 : ";
	cin.getline(dessert, arSize);

	cout << "맛있는 " << dessert << " 디저트를 준비했습니다. " << name << "님!" << endl;

	return 0;
}