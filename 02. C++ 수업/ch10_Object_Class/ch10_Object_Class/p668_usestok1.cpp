#include <iostream>
#include "p664_stock10.h"

int main()
{
	using std::cout;
	using std::endl;

	Stock stock1("NanoSmart", 12, 20.0);
	cout << "\n�����ڸ� ����Ͽ� ���ο� ��ü���� �����մϴ�.\n";
	stock1.Show();
	cout << endl;
	Stock stock2 = Stock("Boffo Objects", 2, 2.0);
	stock2.Show();

	cout << "\nstock1�� stock2�� �����Ѵ�.\n";
	stock2 = stock1;
	cout << "stock1�� stock2�� ����Ѵ�.\n\n";
	stock1.Show();
	cout << endl;
	stock2.Show();

	cout << "\n�����ڸ� ����Ͽ� ��ü�� �缳���Ѵ�.\n";
	stock1 = Stock("Nifty Foods", 10, 50.0);	// �ӽ� ��ü
	cout << "\n���ŵ� stock1\n";
	stock1.Show();
	cout << "\n���α׷��� �����մϴ�.\n\n";
	
	return 0;
}
