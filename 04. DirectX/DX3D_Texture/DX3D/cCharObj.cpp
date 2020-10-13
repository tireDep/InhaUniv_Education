#include "stdafx.h"
#include "cCharObj.h"

cCharObj::cCharObj() : 
	m_ulRefCount(1)
{
	// AddObject(this);
}

cCharObj::~cCharObj(void)
{
	// RemoveObject(this);
}

void cCharObj::AddRef()
{
	++m_ulRefCount;
}

void cCharObj::Release()
{
	--m_ulRefCount;

	if (m_ulRefCount == 0)
		delete this;
}
