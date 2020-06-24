#include<iostream>

namespace Jack
{
	double pail;
	void fetch() {}	// Jill에도 존재(변수)
	int pal;	// Jill에도 존재(변수)
	struct Well
	{

	};
}

namespace Jill
{
	double bucket(double n) { return 1.0; }
	double fetch;	// Jack에도 존재(함수)
	int pal;	// Jack에도 존재(변수)
	struct Hill
	{

	};
}

/*
------------------------------------------------
이름 공간 안에 using 선언 사용 가능 -> 권장 x
------------------------------------------------
*/

using namespace std;
using namespace Jack;
using namespace Jill;

int main()
{
	// pal = 10;	// 어느 이름공간의 pal인지 알 수 x
	Jack::pal = 10;
	Jill::pal = 11;

	using Jack::pal;
	pal = 20;

	using Jill::fetch;	// 동일한 이름의 변수와 함수가 존재함
	fetch = 50;
	cout << fetch << endl;
}