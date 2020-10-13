#pragma once
#include "stdafx.h"

#define g_pTextureManager cCharTextureManager::GetInstance()

class cCharTextureManager
{
private:
	Singletone(cCharTextureManager);

	map<string, LPDIRECT3DTEXTURE9> m_mapTexture;

public:
	LPDIRECT3DTEXTURE9 GetTexture(char* szFullPath);
	LPDIRECT3DTEXTURE9 GetTexture(string& sFullPath);

	void Destroy();

};