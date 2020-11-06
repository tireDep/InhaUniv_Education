#pragma once
#include "Listener.h"

class CObjectCreate : public IListener
{
public:
	CObjectCreate();
	~CObjectCreate();

	void ReceiveMsg(string msg);
	string GetName();
};

