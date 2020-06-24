#pragma once

#include<string>

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	inline void Set_tot()
	{
		total_val = shares * share_val;
	}

public:
	void Acquire(const std::string &co, long n, double pr);
	void Buy(long num, double price);
	void Sell(long num, double price);
	void Update(double price);

	inline void show()
	{
		std::cout << "ȸ��� : " << company
			<< ", �ֽ� �� : " << shares << std::endl
			<< "�ְ� : $" << share_val
			<< ", �ֽ� �� ��ġ : $" << total_val << std::endl;
	}	// �ζ��� �Լ� �ۼ���
};
