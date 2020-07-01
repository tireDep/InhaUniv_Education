#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

// 추상화 기초 클래스
ACCTABC_C::ACCTABC_C(const std::string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void ACCTABC_C::Deposit(double amt)
{
	if (amt < 0)
		cout << "마이너스 입금은 허용되지 않습니다.\n"
		<< "그래서 입금이 취소되었습니다.\n";
	else
		balance += amt;
}

void ACCTABC_C::Withdraw(double amt)
{
	balance -= amt;
}

ACCTABC_C::Formatting ACCTABC_C::SetFormat() const
{
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	
	return f;
}
void ACCTABC_C::Restore(Formatting &f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}

// Brass 메서드
void Brass_C::Withdraw(double amt)
{
	if (amt < 0)
		cout << "마이너스 인출은 허용되지 않습니다.\n"
		<< "그래서 인출이 취소되었습니다.\n";
	else if (amt <= Balance())
		ACCTABC_C::Withdraw(amt);
	else
		cout << "인출을 요구한 금액 $ " << amt
		<< "가 현재 잔액을 초과합니다.\n"
		<< "그래서 인출이 취소되었습니다.\n";
}

void Brass_C::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Brass 고객 : " << FullName() << endl;
	cout << "계좌번호 : " << AcctNum() << endl;
	cout << "현재잔액 : " << Balance() << endl;
	Restore(f);
}

// BrassPlus 메서드
BrassPlus_C::BrassPlus_C(const std::string &s, long an, double bal, double ml, double r) : ACCTABC_C(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus_C::BrassPlus_C(const Brass_C & ba, double ml, double r) : ACCTABC_C(ba)	// 암시적 복사 생성자 사용
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus_C::Withdraw(double amt)
{
	Formatting f = SetFormat();
	double bal = Balance();

	if (amt <= bal)
		ACCTABC_C::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "당좌 대월 금액 : $" << advance << endl;
		cout << "당좌 대월 이자 : $" << advance*rate << endl;
		Deposit(advance);
		ACCTABC_C::Withdraw(amt);
	}
	else
		cout << "당좌 대월 한도가 초과되어 거래가 취소되었습니다.\n";

	Restore(f);
}

void BrassPlus_C::ViewAcct() const
{
	Formatting f = SetFormat();

	cout << "BrassPlus 고객 : " << FullName() << endl;
	cout << "계좌번호 : " << AcctNum() << endl;
	cout << "현재 잔액 : $" << Balance() << endl;
	cout << "당좌 대월 한도 : $" << maxLoan << endl;
	cout << "상환할 원리금 : $" << owesBank << endl;
	cout.precision(3);
	cout << "당좌 대월 이자율 : " << 100 * rate << "%\n";

	Restore(f);
}