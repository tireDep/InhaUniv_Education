#pragma once
#include "BasicHeader.h"

class cCharacter
{
public:
	cCharacter();
	virtual ~cCharacter();

	virtual void SetUp() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};