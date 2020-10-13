#include "stdafx.h"
#include "cCharTextureManager.h"

LPDIRECT3DTEXTURE9 cCharTextureManager::GetTexture(char * szFullPath)
{
	if (m_mapTexture.find(szFullPath) == m_mapTexture.end())
	{
		D3DXCreateTextureFromFileA(g_pD3DDevice, szFullPath, &m_mapTexture[szFullPath]);
	}

	return m_mapTexture[szFullPath];
}

LPDIRECT3DTEXTURE9 cCharTextureManager::GetTexture(string & sFullPath)
{
	return GetTexture((char*)sFullPath.c_str());
}

void cCharTextureManager::Destroy()
{
	for each(auto it in m_mapTexture)
	{
		SafeRelease(it.second);
	}

	m_mapTexture.clear();
}
