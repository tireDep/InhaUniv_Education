// 520p
// 함수 템플릿 사용하기

#include<iostream>

template <typename T>
void Swap(T &a, T &b);	
// 함수 템플릿 원형
// T는 Any 형의 변수

using namespace std;

int main()
{
	int i = 10, j = 20;

	cout << "i, j = " << i << ", " << j << endl;
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout<<"이제 i, j = " << i << ", " << j << endl;

	double x = 24.5, y = 81.7;
	cout << "\nx, y = " << x << ", " << y << endl;
	cout << "컴파일러가 생성한 double형 교환기를 사용하면\n";
	Swap(x, y);
	cout << "이제 x, y = " << x << ", " << y << endl;

	return 0;

}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}