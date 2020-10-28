#include "stdafx.h"
#include "SpriteManager.h"
#include "UI.h"
#include "Button.h"

C_UI::C_UI() :
	m_pSprite(NULL),
	// m_pTextureUI(NULL), 
	m_isLBtnPush(false),
	m_isUI(true),
	m_index(0)
{
	m_movePos = { 0,0 };
	m_prevMousPos = { 0,0 };

	D3DXMatrixIdentity(&m_matWorld);

	m_center = { 0,0 };

	m_parentCenter = { 0,0 };
}

C_UI::~C_UI()
{
	SafeRelease(m_pSprite);
	// SafeRelease(m_pTextureUI);

	for each(auto it in m_vecCharUI)
		SafeDelete(it);
	m_vecCharUI.clear();
}

void C_UI::SetUp(char* szFolder, char* szFile)
{
	string sFullPath = string(szFolder) + string("/") + string(szFile);

	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);
	LPDIRECT3DTEXTURE9 temp;
	g_pSpriteManager->GetTexture(sFullPath, m_stImgInfo, temp);
	m_vecTextureUI.push_back(temp);

	m_parentCenter = { 0,0 };
	SetRect(&rc, 0, 0, m_stImgInfo.Width, m_stImgInfo.Height);

	POINT tempC = { m_stImgInfo.Width / 4, m_stImgInfo.Height / 2 };
	C_Button* button = new C_Button;
	button->SetUp("UI", "btn-med-over.png", tempC);
	m_vecCharUI.push_back(button);

	tempC.y = m_stImgInfo.Height / 1.5;
	C_Button* button2 = new C_Button;
	button2->SetUp("UI", "btn-med-over.png", tempC);
	m_vecCharUI.push_back(button2);
}

void C_UI::Update()
{
	RECT rectView;
	GetClientRect(g_hWnd, &rectView);

	D3DXMATRIXA16 matS, matR, matT;
	D3DXMatrixScaling(&matS, 1.0f, 1.0f, 0.0f);
	D3DXMatrixTranslation(&matT, 0, 0, 0);
	D3DXMatrixIdentity(&matR);

	m_matWorld = matS * matR * matT;

	for (int i = 0; i < m_vecCharUI.size(); i++)
		m_vecCharUI[i]->m_matWorld = m_matWorld;
}

void C_UI::Render()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	m_pSprite->SetTransform(&m_matWorld);

	m_pSprite->Draw(m_vecTextureUI[m_index],
		NULL,
		&D3DXVECTOR3(0, 0, 0),
		&D3DXVECTOR3(m_parentCenter.x + m_movePos.x, m_parentCenter.y + m_movePos.y, 0),
		D3DCOLOR_ARGB(150, 255, 255, 255));

	m_pSprite->End();

	if (m_vecCharUI.size() != 0)
	{
		for (int i = 0; i < m_vecCharUI.size(); i++)
			m_vecCharUI[i]->Render();
	}	// : if

}

void C_UI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < m_vecCharUI.size(); i++)
		m_vecCharUI[i]->WndProc(hWnd, message, wParam, lParam);

	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		// UI가 켜져 있을 때, UI 부위가 선택 되었을 때
		if (m_isUI)
		{
			m_prevMousPos.x = LOWORD(lParam);
			m_prevMousPos.y = HIWORD(lParam);
			m_isLBtnPush = true;
		}
	}
	break;

	case WM_LBUTTONUP:
		m_isLBtnPush = false;
		break;

	case WM_MOUSEMOVE:
	{
		POINT nowPos;
		nowPos.x = LOWORD(lParam);
		nowPos.y = HIWORD(lParam);

		if (m_isLBtnPush)
		{
			m_movePos.x = nowPos.x - m_prevMousPos.x;
			m_movePos.y = nowPos.y - m_prevMousPos.y;
		}

		if ((rc.left + m_parentCenter.x  - m_stImgInfo.Width / 2.0f  <= nowPos.x && rc.right + m_parentCenter.x - m_stImgInfo.Width / 2.0f >= nowPos.x) 
		 	 && (rc.top + m_parentCenter.y - m_stImgInfo.Height / 2.0f <= nowPos.y && rc.bottom + m_parentCenter.y + m_stImgInfo.Height / 2.0f >= nowPos.y))
		{
			if (m_vecTextureUI.size() > 1)
				m_index = 1;
			else
				m_index = 0;
		}

	}
	break;
	case WM_SIZE:
		//// >> setCenter
		//RECT rectView;
		//GetClientRect(g_hWnd, &rectView);

		//m_center.x = rectView.right / 2 - m_stImgInfo.Width / 2;// +m_movePos.x;
		//m_center.y = rectView.bottom / 2 - m_stImgInfo.Height / 2;// +m_movePos.y;
		//// m_center.x = m_stImgInfo.Width;
		//// m_center.y = m_stImgInfo.Height;

		//// << setCenter
		break;
	}
}
