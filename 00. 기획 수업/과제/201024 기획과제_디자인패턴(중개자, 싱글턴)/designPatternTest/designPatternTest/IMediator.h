#pragma once
#include <string>

class ICollegue;

using std::string;

class IMediator
{
public:
	IMediator() { }
	virtual ~IMediator() { }

	virtual void SetUp() = 0;
	virtual void Notify(ICollegue* sender, string strMsg) const = 0;

};
