#pragma once
#include <iostream>
#include <string>

using namespace std;

class IListener
{
protected:
	string m_strName;

public:
	virtual ~IListener() { }
	virtual void ReceiveMsg(string msg) { }
	virtual string GetName() { return string(); }
};

