#include "SingletonObj.h"

void CSingletonObj::PrintSuccess()
{
	cout << "Success" << endl;
}

void CSingletonObj::SetNumber(int set)
{
	m_iNum = set;
}

void CSingletonObj::PrintNumber()
{
	cout << m_iNum << endl;
}
