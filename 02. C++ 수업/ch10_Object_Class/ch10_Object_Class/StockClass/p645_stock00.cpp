#include <iostream>
#include "p639_stock00.h"

void Stock::Acquire(const std::string &co, long n, double pr) 
{
	company = co;
	if (n < 0)
	{
		std::cout << "주식 수는 음수가 될 수 없으므로, " << company << " shares를 0으로 설정합니다.\n";
		shares = 0;
	}
	else
		shares = n;
	
	share_val = pr;
	Set_tot();
}

void Stock::Buy(long num, double price) 
{
	if (num < 0)
		std::cout << "매입 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다.\n";
	else
	{
		shares += num;
		share_val = price;
		Set_tot();
	}
}

void Stock::Sell(long num, double price) 
{
	using std::cout;
	if (num < 0)
		std::cout << "매도 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다.\n";
	else if (num > shares)
		std::cout << "보유 주식보다 많은 주식을 매도할 수 없으므로, 거래가 취소되었습니다.\n";
	else
	{
		shares -= num;
		share_val = price;
		Set_tot();
	}
}

void Stock::Update(double price) 
{
	share_val = price;
	Set_tot();
}
