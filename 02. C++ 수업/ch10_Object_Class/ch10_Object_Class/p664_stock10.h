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

	inline void Show() const	// ���� ����Ǵ� ������ �־�� �ȵ��� ���, �Լ��� ���� const�� �ڿ� �ۼ�
	{
		using std::cout;
		using std::ios_base;	// set format to #.###
		ios_base::fmtflags orig
			= cout.setf(ios_base::fixed, ios_base::floatfield);
		std::streamsize prec = cout.precision(3);

		cout << "ȸ��� : " << company
			<< ", �ֽ� �� : " << shares << std::endl;
		cout << "�ְ� : $" << share_val;
		cout.precision(2);	// set format to #.##
		cout << ", �ֽ� �� ��ġ : $" << total_val << std::endl;

		// ���� ���� ����
		cout.setf(orig, ios_base::floatfield);
		cout.precision(prec);
	}	// �ζ��� �Լ� �ۼ���
};
