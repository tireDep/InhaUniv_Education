#pragma once
#include "stdafx.h"

#define g_pTextureManager cTextureManger::GetInstance()

class cTextureManager
{
private:
	Singletone(cTextureManager);

public:

};