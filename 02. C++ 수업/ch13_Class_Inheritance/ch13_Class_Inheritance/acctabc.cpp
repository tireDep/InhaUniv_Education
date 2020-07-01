#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

// �߻�ȭ ���� Ŭ����
ACCTABC_C::ACCTABC_C(const std::string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void ACCTABC_C::Deposit(double amt)
{
	if (amt < 0)
		cout << "���̳ʽ� �Ա��� ������ �ʽ��ϴ�.\n"
		<< "�׷��� �Ա��� ��ҵǾ����ϴ�.\n";
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

// Brass �޼���
void Brass_C::Withdraw(double amt)
{
	if (amt < 0)
		cout << "���̳ʽ� ������ ������ �ʽ��ϴ�.\n"
		<< "�׷��� ������ ��ҵǾ����ϴ�.\n";
	else if (amt <= Balance())
		ACCTABC_C::Withdraw(amt);
	else
		cout << "������ �䱸�� �ݾ� $ " << amt
		<< "�� ���� �ܾ��� �ʰ��մϴ�.\n"
		<< "�׷��� ������ ��ҵǾ����ϴ�.\n";
}

void Brass_C::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Brass �� : " << FullName() << endl;
	cout << "���¹�ȣ : " << AcctNum() << endl;
	cout << "�����ܾ� : " << Balance() << endl;
	Restore(f);
}

// BrassPlus �޼���
BrassPlus_C::BrassPlus_C(const std::string &s, long an, double bal, double ml, double r) : ACCTABC_C(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus_C::BrassPlus_C(const Brass_C & ba, double ml, double r) : ACCTABC_C(ba)	// �Ͻ��� ���� ������ ���
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
		cout << "���� ��� �ݾ� : $" << advance << endl;
		cout << "���� ��� ���� : $" << advance*rate << endl;
		Deposit(advance);
		ACCTABC_C::Withdraw(amt);
	}
	else
		cout << "���� ��� �ѵ��� �ʰ��Ǿ� �ŷ��� ��ҵǾ����ϴ�.\n";

	Restore(f);
}

void BrassPlus_C::ViewAcct() const
{
	Formatting f = SetFormat();

	cout << "BrassPlus �� : " << FullName() << endl;
	cout << "���¹�ȣ : " << AcctNum() << endl;
	cout << "���� �ܾ� : $" << Balance() << endl;
	cout << "���� ��� �ѵ� : $" << maxLoan << endl;
	cout << "��ȯ�� ������ : $" << owesBank << endl;
	cout.precision(3);
	cout << "���� ��� ������ : " << 100 * rate << "%\n";

	Restore(f);
}