#pragma once
#include "stdafx.h"
#include "cCubeNode.h"

class cBody : public cCubeNode
{
private:

public:
	cBody();
	~cBody();

	virtual void SetUp() override;
};
