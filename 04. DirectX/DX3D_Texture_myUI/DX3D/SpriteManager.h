#pragma once

#define g_pSpriteManager CSpriteManager::GetInstance()

class CSpriteManager
{
private:
	Singletone(CSpriteManager);

public:
	void GetTexture(string sFullPath, D3DXIMAGE_INFO& imgInfo, LPDIRECT3DTEXTURE9& textureUI);
};

