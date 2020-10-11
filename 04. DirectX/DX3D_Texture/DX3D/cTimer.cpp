#include "stdafx.h"

cTimer::cTimer()
{
}

cTimer * cTimer::GetInstance()
{
	static cTimer timer;
	return &timer;
}

cTimer::~cTimer()
{
}
