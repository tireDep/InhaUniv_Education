#pragma once

#include<string>

namespace pers
{
	struct PERSON_S
	{
		std::string fname;
		std::string lname;
	};

	void GetPerson(PERSON_S &);
	void ShowPerson(const PERSON_S &);
}

namespace debts
{
	using namespace pers;

	struct DEBT_S
	{
		PERSON_S name;
		double amount;
	};

	void GetDebt(DEBT_S &);
	void ShowDebt(const DEBT_S &);
	double SumDebts(const DEBT_S ar[], int n);
}