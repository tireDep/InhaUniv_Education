#pragma once
#include "stdafx.h"
// point normal texture

class cCubePNT
{
private:

protected:
	std::vector<stPNT_Vertext> m_vecVertex;

public:
	cCubePNT();
	virtual ~cCubePNT(void);
	virtual void SetUp();
	virtual void Update();
	virtual void Render();
};
