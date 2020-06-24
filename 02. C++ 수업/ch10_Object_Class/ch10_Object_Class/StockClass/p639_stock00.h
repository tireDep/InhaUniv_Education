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
		std::cout << "회사명 : " << company
			<< ", 주식 수 : " << shares << std::endl
			<< "주가 : $" << share_val
			<< ", 주식 총 가치 : $" << total_val << std::endl;
	}	// 인라인 함수 작성법
};
