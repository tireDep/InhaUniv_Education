#include <iostream>
#include "StockClass\p639_stock00.h"	// #include "p639_stock00.h"

/*
-----------------------------------------------------------------
[�ٸ� ��ġ�� ������ ��]
- #include "../������"	// ���� ����
- #include "Stock/stock.h"	// ���� �� ����

���α׷� �Ը� Ŀ����, Ŭ������ �������� ���� ������ �����ϰ� ��
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
