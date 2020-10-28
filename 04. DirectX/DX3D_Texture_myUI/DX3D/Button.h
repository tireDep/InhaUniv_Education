#pragma once
#include "UI.h"

class C_Button : public C_UI
{
public:
	C_Button();
	~C_Button();

	void SetUp(char* szFolder, char* szFile);
	void Update();
	void Render();
};

