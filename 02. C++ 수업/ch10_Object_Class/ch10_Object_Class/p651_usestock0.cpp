#include <iostream>
#include "StockClass\p639_stock00.h"	// #include "p639_stock00.h"

/*
-----------------------------------------------------------------
[다른 위치에 존재할 때]
- #include "../폴더명"	// 상위 폴더
- #include "Stock/stock.h"	// 폴더 내 존재

프로그램 규모가 커지고, 클래스가 많아지면 폴더 단위로 관리하게 됨
-----------------------------------------------------------------
*/

using namespace std;

int main()
{
	Stock fluffy_the_cat;
	fluffy_the_cat.Acquire("NanoSmart", 20, 12.50);
	fluffy_the_cat.show();
	cout << endl;

	fluffy_the_cat.Buy(15, 18.125);
	fluffy_the_cat.show();
	cout << endl;

	fluffy_the_cat.Sell(400, 20.00);
	fluffy_the_cat.show();
	cout << endl;

	fluffy_the_cat.Buy(300000, 40.125);
	fluffy_the_cat.show();
	cout << endl;

	fluffy_the_cat.Sell(300000, 0.125);
	fluffy_the_cat.show();

	return 0;
}
