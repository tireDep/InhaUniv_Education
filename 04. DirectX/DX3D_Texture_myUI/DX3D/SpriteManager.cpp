#include "stdafx.h"
#include "SpriteManager.h"

CSpriteManager::CSpriteManager()
{
}

CSpriteManager::~CSpriteManager()
{
}

void CSpriteManager::GetTexture(string sFullPath, D3DXIMAGE_INFO& imgInfo, LPDIRECT3DTEXTURE9& textureUI)
{
	D3DXCreateTextureFromFileExA(
		g_pD3DDevice,
		sFullPath.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		0,
		&imgInfo,
		NULL,
		&textureUI
	);
}
