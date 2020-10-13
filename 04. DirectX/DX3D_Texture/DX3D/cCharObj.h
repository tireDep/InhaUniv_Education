#pragma once
#include "cMtlTex.h"

class cCharObj
{
private:
	ULONG m_ulRefCount;

public:
	cCharObj();
	virtual ~cCharObj(void);
	virtual void AddRef();
	virtual void Release();
};