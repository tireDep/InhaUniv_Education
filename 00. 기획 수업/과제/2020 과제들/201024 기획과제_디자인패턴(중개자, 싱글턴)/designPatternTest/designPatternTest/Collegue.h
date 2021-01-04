#pragma once
#include <iostream>
#include "IMediator.h"
#include "ICollegue.h"

using namespace std;

class CCollegueA : public ICollegue
{
public:
	CCollegueA() { }
	~CCollegueA() { }

	void DoA()
	{
		cout << "Coll A" << endl;
		this->m_mediator->Notify(this, "A");
	}

	virtual void ReciveMessage(string strMsg)
	{
		cout << "Success\nExit" << endl;
	}
};

class CCollegueB : public ICollegue
{
public:
	CCollegueB() { }
	~CCollegueB() { }

	void DoC()
	{
		cout << "Coll C" << endl;
		this->m_mediator->Notify(this, "C");
	}

	void DoD()
	{
		cout << "Coll D" << endl;
		this->m_mediator->Notify(this, "D");
	}

	virtual void ReciveMessage(string strMsg)
	{
		cout << "ReciveMessage" << endl;
		DoD();
	}
};

