#pragma once
#include "stdafx.h"

class cMainGame
{
private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pDevice;

public:
	cMainGame();
	~cMainGame();

	void SetUp();
	void Update();
	void Render();

};