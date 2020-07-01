#pragma once

/*
--------------------------------------------
[가상 클래스]
- 클래스 내부에 순수 가상함수가 존재함
- 'virtual 함수명() = 0' 의 형태

[인터페이스]
- 순수 가상함수만 존재하는 클래스
- 이러한 기능이 있다는 것을 알려주는 클래스
- 접두어로 I가 붙음
--------------------------------------------
*/

#include<iostream>
#include<string>

class ACCTABC_C	// 가상 클래스 : virtual 함수명 = 0; 존재
{
private:
	std::string fullName;
	long acctNum;
	double balance;

protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag; 
		std::streamsize pr;
	};

	const std::string & FullName() const { return fullName; }
	long AcctNum() const { return acctNum; }
	Formatting SetFormat() const;
	void Restore(Formatting &f) const;

public:
	ACCTABC_C(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;	// 순수 가상 함수
	double Balance() const { return balance; }
	virtual void ViewAcct() const = 0;	// 순수 가상 함수
	virtual ~ACCTABC_C() {}

};

// Brass Account Class

class Brass_C :public ACCTABC_C
{
public:
	Brass_C(const std::string &s = "Nullbody", long an = -1, double bal = 0.0) :ACCTABC_C(s, an, bal) {}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass_C() { }
};

// Brass Plus Account Class
class BrassPlus_C :public ACCTABC_C
{
private:
	double maxLoan;
	double rate;
	double owesBank;

public:
	BrassPlus_C(const std::string &s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus_C(const Brass_C & ba, double ml = 500, double r = 0.1);
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
	virtual ~BrassPlus_C() { }
};