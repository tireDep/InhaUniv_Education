#include "ConcreteMediator.h"

CConcreteMediator::CConcreteMediator()
{
}

CConcreteMediator::~CConcreteMediator()
{
}

void CConcreteMediator::SetUp()
{
}

void CConcreteMediator::Notify(ICollegue * sender, string strMsg) const
{
	for (int i = 0; i < m_vecCollegue.size(); i++)
	{
		if (m_vecCollegue[i] != sender)
			m_vecCollegue[i]->ReciveMessage(strMsg);
	}
}

void CConcreteMediator::AddCollegue(ICollegue * addColl)
{
	m_vecCollegue.push_back(addColl);
	addColl->SetMediator(this);
}

void CConcreteMediator::RemoveCollegue(ICollegue * removeColl)
{
	vector<ICollegue*>::iterator it;
	for (it = m_vecCollegue.begin(); it < m_vecCollegue.end();)
	{
		if (*it == removeColl)
			it = m_vecCollegue.emplace(it);
		else
			it++;
	}
}
