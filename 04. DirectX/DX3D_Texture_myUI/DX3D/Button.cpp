#include "stdafx.h"
#include "SpriteManager.h"
#include "Button.h"

C_Button::C_Button()
{
}

C_Button::~C_Button()
{
}

void C_Button::SetUp(char * szFolder, char * szFile, POINT parentCenter)
{
	string sFullPath = string(szFolder) + string("/") + string(szFile);

	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	LPDIRECT3DTEXTURE9 temp;
	g_pSpriteManager->GetTexture(sFullPath, m_stImgInfo, temp);
	m_vecTextureUI.push_back(temp);

	sFullPath = string(szFolder) + string("/") + string("btn-med-down.png");
	g_pSpriteManager->GetTexture(sFullPath, m_stImgInfo, temp);
	m_vecTextureUI.push_back(temp);

	sFullPath = string(szFolder) + string("/") + string("btn-med-up.png");
	g_pSpriteManager->GetTexture(sFullPath, m_stImgInfo, temp);
	m_vecTextureUI.push_back(temp);

	SetRect(&rc, 0, 0, m_stImgInfo.Width, m_stImgInfo.Height);

	m_parentCenter = parentCenter;
}

void C_Button::Update()
{
}
