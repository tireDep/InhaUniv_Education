#include "stdafx.h"
#include "SpriteManager.h"
#include "Button.h"

C_Button::C_Button()
{
}

C_Button::~C_Button()
{
}

void C_Button::SetUp(char * szFolder, char * szFile)
{
	string sFullPath = string(szFolder) + string("/") + string(szFile);

	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);
	g_pSpriteManager->GetTexture(sFullPath, m_stImgInfo, m_pTextureUI);
}

void C_Button::Update()
{
}

void C_Button::Render()
{
	RECT rc;
	SetRect(&rc, 0, 0, m_stImgInfo.Width, m_stImgInfo.Height);

	RECT rectView;
	GetClientRect(g_hWnd, &rectView);

	POINT pos;
	pos.x = rectView.right / 2 - m_stImgInfo.Width / 2;
	pos.y = rectView.bottom / 2 - m_stImgInfo.Height / 2;

	D3DXMATRIXA16 matS, matR, matT, matWorld;
	D3DXMatrixIdentity(&matS);
	D3DXMatrixTranslation(&matT, pos.x, pos.y, 0);

	static float fAngle = 0.0f;
	fAngle += 0.01f;
	D3DXMatrixRotationZ(&matR, fAngle);

	matWorld = matS * matR * matT;
	m_pSprite->SetTransform(&matT);

	m_pSprite->Draw(m_pTextureUI,
		NULL,
		&D3DXVECTOR3(0, 0, 0), // anchor ? 
		&D3DXVECTOR3(0, 0, 0), // pivot  ?
		D3DCOLOR_ARGB(150, 255, 255, 255));

	m_pSprite->End();
}
