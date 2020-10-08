#pragma once
#include "stdafx.h"

#define g_pObjectManger cObjectManager::GetInstance()

class cObjectManager
{
private:
	Singletone(cObjectManager);

public:

};