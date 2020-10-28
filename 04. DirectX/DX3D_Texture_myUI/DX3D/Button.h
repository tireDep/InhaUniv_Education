#pragma once
#include "UI.h"

class C_Button : public C_UI
{
private:
	Synthesize(D3DXMATRIXA16*, m_matWorld, MatWorld);

public:
	C_Button();
	~C_Button();

	void SetUp(char* szFolder, char* szFile, POINT parentCenter);
	void Update();
};

