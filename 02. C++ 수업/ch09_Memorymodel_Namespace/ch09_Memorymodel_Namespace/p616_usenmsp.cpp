#include<iostream>
#include"p616_namesp.h"

void Other(void);
void Another(void);

int main()
{
	using debts::DEBT_S;
	using debts::ShowDebt;

	DEBT_S golf = { {"Benny","Goatniff"},120.0 };
	ShowDebt(golf);
	Other();
	Another();

	return 0;
}

void Other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;

	PERSON_S dg = { "Doodles","Glister" };
	ShowPerson(dg);
	cout << endl;
	
	DEBT_S zippy[3];
	for (int i = 0; i < 3; i++)
		GetDebt(zippy[i]);

	for (int i = 0; i < 3; i++)
		ShowDebt(zippy[i]);
	cout << "ºÎÃ¤ ÃÑ¾× : $" << SumDebts(zippy, 3) << endl;
	
	return;
}

void Another(void)
{
	using pers::PERSON_S;

	PERSON_S collector = { "Milo","Rightshift" };
	pers::ShowPerson(collector);
	std::cout << std::endl;

	return;
}