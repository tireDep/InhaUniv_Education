// p639

#pragma once

/*
---------------------------------------------------------------

[알아두기]
#pragma once 대신에
#ifdef 를 사용해도 되나, 사용할 경우 #endif를 꼭 같이 사용해야함

ex)
#ifdef _Stock
#define _Stock

// 내용 작성

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

설계의 추상화, 데이터 은닉, 캡슐화, 인터페이스
클래스 멤버 함수, 객체

-----------------------------------------------------
*/
