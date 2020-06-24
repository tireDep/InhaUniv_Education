#include <iostream>
#include "p664_stock10.h"

int main()
{
	using std::cout;
	using std::endl;

	Stock stock1("NanoSmart", 12, 20.0);
	cout << "\n생성자를 사용하여 새로운 객체들을 생성합니다.\n";
	stock1.Show();
	cout << endl;
	Stock stock2 = Stock("Boffo Objects", 2, 2.0);
	stock2.Show();

	cout << "\nstock1을 stock2에 대입한다.\n";
	stock2 = stock1;
	cout << "stock1과 stock2를 출력한다.\n\n";
	stock1.Show();
	cout << endl;
	stock2.Show();

	cout << "\n생성자를 사용하여 객체를 재설정한다.\n";
	stock1 = Stock("Nifty Foods", 10, 50.0);	// 임시 객체
	cout << "\n갱신된 stock1\n";
	stock1.Show();
	cout << "\n프로그램을 종료합니다.\n\n";
	
	return 0;
}
