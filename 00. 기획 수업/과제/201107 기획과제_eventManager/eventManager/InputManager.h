#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class IListener;

class CInputManager
{
private:
	vector<IListener*> m_vecListener;
	CInputManager();

public:
	static CInputManager* GetInstance();
	~CInputManager();

	bool AddListener(IListener* listener);
	bool RemoveListener(IListener* listener);

	bool CheckInput();
};

