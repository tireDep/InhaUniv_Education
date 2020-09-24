#pragma once
#include "stdafx.h"

class cMainGame
{
private:
	vector<stPC_Vertex> m_vecLineVertex;

public:
	cMainGame();
	~cMainGame();

	void SetUp();
	void Update();
	void Render();

	void SetUp_Line();
	void Draw_Line();
};