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
	Stock();
	Stock(const std::string &co, long n = 0, double pr = 0.0);
	~Stock();

	void Buy(long num, double price);
	void Sell(long num, double price);
	void Update(double price);

	inline void Show() const	// 값이 변경되는 내용이 있어서는 안됨을 명시, 함수는 보통 const를 뒤에 작성
	{
		using std::cout;
		using std::ios_base;	// set format to #.###
		ios_base::fmtflags orig
			= cout.setf(ios_base::fixed, ios_base::floatfield);
		std::streamsize prec = cout.precision(3);

		cout << "회사명 : " << company
			<< ", 주식 수 : " << shares << std::endl;
		cout << "주가 : $" << share_val;
		cout.precision(2);	// set format to #.##
		cout << ", 주식 총 가치 : $" << total_val << std::endl;

		// 원본 포멧 저장
		cout.setf(orig, ios_base::floatfield);
		cout.precision(prec);
	}	// 인라인 함수 작성법
};
