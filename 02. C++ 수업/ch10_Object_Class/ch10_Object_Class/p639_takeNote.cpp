// p639

#pragma once

/*
---------------------------------------------------------------

[�˾Ƶα�]
#pragma once ��ſ�
#ifdef �� ����ص� �ǳ�, ����� ��� #endif�� �� ���� ����ؾ���

ex)
#ifdef _Stock
#define _Stock

// ���� �ۼ�

#endif

---------------------------------------------------------------
*/

#include<string>

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot()
	{
		total_val = shares * share_val;
	}

public:
	void Acquire(const std::string &cp, long n, double pt) {}
	void Buy(long num, double price) {}
	void Sell(long num, double price) {}
	void Update(double price) {}
	void show() {}
};

/*
-----------------------------------------------------

private / protected / public

������ �߻�ȭ, ������ ����, ĸ��ȭ, �������̽�
Ŭ���� ��� �Լ�, ��ü

-----------------------------------------------------
*/
