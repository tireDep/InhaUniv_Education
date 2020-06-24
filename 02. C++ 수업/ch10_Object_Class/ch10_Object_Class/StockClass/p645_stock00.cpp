#include <iostream>
#include "p639_stock00.h"

void Stock::Acquire(const std::string &co, long n, double pr) 
{
	company = co;
	if (n < 0)
	{
		std::cout << "�ֽ� ���� ������ �� �� �����Ƿ�, " << company << " shares�� 0���� �����մϴ�.\n";
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
		std::cout << "���� �ֽ� ���� ������ �� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
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
		std::cout << "�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
	else if (num > shares)
		std::cout << "���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
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
