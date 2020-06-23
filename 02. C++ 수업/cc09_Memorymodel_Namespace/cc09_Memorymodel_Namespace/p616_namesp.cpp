#include<iostream>
#include"p616_namesp.h"

namespace pers
{
	using std::cout;
	using std::cin;

	void GetPerson(PERSON_S & rp)
	{
		cout << "이름을 입력하십시오 : ";
		cin >> rp.fname;
		cout << "성씨를 입력하십시오 : ";
		cin >> rp.lname;
	}

	void ShowPerson(const PERSON_S &rp)
	{
		std::cout << rp.lname << ", " << rp.fname;
	}
}

namespace debts
{
	void GetDebt(DEBT_S &rd)
	{
		GetPerson(rd.name);
		std::cout << "부채를 입력하십시오 : $";
		std::cin >> rd.amount;
	}

	void ShowDebt(const DEBT_S &rd)
	{
		pers::ShowPerson(rd.name);
		std::cout << " : $" << rd.amount << std::endl;
	}

	double SumDebts(const DEBT_S ar[], int n)
	{
		double total = 0;
		for (int i = 0; i < n; i++)
			total += ar[i].amount;
		return total;
	}
}