#pragma once
#include "Listener.h"

class CPlayer : public IListener
{
public:
	CPlayer();
	~CPlayer();

	void ReceiveMsg(string msg) override;
	string GetName() override;
};

