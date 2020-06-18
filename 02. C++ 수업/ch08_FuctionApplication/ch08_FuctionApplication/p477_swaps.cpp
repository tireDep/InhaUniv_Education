// 참조변수
// 477p

#include<iostream>

void SwapR(int &a, int &b);	// 변수를 전달
void SwapP(int *a, int *b);	// 변수의 주소를 전달
void SwapV(int a, int b);	// 변수의 값을 전달

/*
-------------------------------------------------------------
void SwapR(int &a, int &b) 식으로 변수 자체를 전달할 때,
값이 변경되는 것을 원하지 않는다면 매개변수에 const 붙여야 함
-------------------------------------------------------------
*/

using namespace std;

int main()
{
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "\n참조를 이용하여 내용들을 교환\n";
	SwapR(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "\n포인터를 이용하여 내용들을 교환\n";
	SwapP(&wallet1, &wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "\n값으로 전달하여 내용교환 시도\n";
	SwapV(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";
}

void SwapR(int &a, int &b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void SwapP(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void SwapV(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}
