#include <iostream>
#include "p664_stock10.h"

Stock::Stock()
{
	std::cout << "����Ʈ �����ڰ� ȣ��Ǿ����ϴ�.\n";
	company = "no name";
	shares = 0;
	share_val = 0;
	total_val = 0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
	std::cout << co << "�� ����ϴ� �����ڰ� ȣ��Ǿ����ϴ�.\n";
	company = co;
	if (n < 0)
	{
		std::cerr << "�ֽ� ���� ������ �� �� �����Ƿ�, " << company << " shares�� 0���� �����մϴ�.\n";
		shares = 0;
	}
	else
		shares = n;

	share_val = pr;
	Set_tot();
}

Stock::~Stock()
{
	std::cout << "�ȳ�, " << company << "!\n";
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
