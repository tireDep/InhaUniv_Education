#include "Listener.h"
#include "InputManager.h"

CInputManager::CInputManager()
{
}

CInputManager* CInputManager::GetInstance()
{
	static CInputManager instance;
	return &instance;
}

CInputManager::~CInputManager()
{
}

bool CInputManager::AddListener(IListener* listener)
{
	for (int i = 0; i < m_vecListener.size(); i++)
	{
		if (listener->GetName() == m_vecListener[i]->GetName())
		{
			cout << "Same Name Existence" << endl;
			return false;
		}
	}

	m_vecListener.push_back(listener);
	return true;
}

bool CInputManager::RemoveListener(IListener* listener)
{
	vector<IListener*>::iterator it;
	for (it = m_vecListener.begin(); it < m_vecListener.end();)
	{
		if ((*it)->GetName() == listener->GetName())
		{
			it = m_vecListener.erase(it);
			return true;
		}
		else
			it++;
	}

	cout << "Fail Remove Listener" << endl;
	return false;
}

bool CInputManager::CheckInput()
{
	string input;
	cin >> input;

	if (input == "q")
		return false;

	for (int i = 0; i < m_vecListener.size(); i++)
		m_vecListener[i]->ReceiveMsg(input);

	return true;
}
