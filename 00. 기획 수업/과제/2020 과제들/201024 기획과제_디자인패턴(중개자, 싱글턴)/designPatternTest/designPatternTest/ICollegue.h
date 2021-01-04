#pragma once
#include <string>

class IMediator;

using std::string;

class ICollegue
{
protected:
	IMediator *m_mediator;

public:
	ICollegue(IMediator *mediator = nullptr) : m_mediator(mediator) { }
	virtual ~ICollegue() { }

	virtual void SetMediator(IMediator* mediator)
	{
		this->m_mediator = mediator;
	}

	virtual void ReciveMessage(string strMsg) = 0;
};
