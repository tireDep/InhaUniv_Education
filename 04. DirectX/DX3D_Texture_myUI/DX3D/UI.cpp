#include "stdafx.h"
#include "SpriteManager.h"
#include "UI.h"
#include "Button.h"

C_UI::C_UI() :
	m_pSprite(NULL),
	m_pTextureUI(NULL), 
	m_isLBtnPush(false),
	m_isUI(true)
{
	m_movePos = { 0,0 };
	m_prevMousPos = { 0,0 };
}

C_UI::~C_UI()
{
	SafeRelease(m_pSprite);
	SafeRelease(m_pTextureUI);

	for each(auto it in m_vecCharUI)
		SafeDelete(it);
	m_vecCharUI.clear();
}

void C_UI::SetUp(char* szFolder, char* szFile)
{
	string sFullPath = string(szFolder) + string("/") + string(szFile);

	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);
	g_pSpriteManager->GetTexture(sFullPath, m_stImgInfo, m_pTextureUI);

	C_Button* button = new C_Button;
	button->SetUp("UI", "Btn_Push.png");
	m_vecCharUI.push_back(button);

	// C_Button* button2 = new C_Button;
	// button2->SetUp("UI", "Btn_Normal.png");
	// m_vecCharUI.push_back(button2);
}

void C_UI::Update()
{
}

void C_UI::Render()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	// RECT rc;
	// SetRect(&rc, 0, 0, m_stImgInfo.Width, m_stImgInfo.Height);

	// >> setCenter
	float setNum = 1.0f;
	RECT rectView;
	GetClientRect(g_hWnd, &rectView);

	POINT pos;
	pos.x = rectView.right / 2 - setNum * m_stImgInfo.Width / 2 + m_movePos.x;
	pos.y = rectView.bottom / 2 - setNum * m_stImgInfo.Height / 2 + m_movePos.y;
	// << setCenter

	D3DXMATRIXA16 matS, matR, matT, matWorld;
	D3DXMatrixScaling(&matS, setNum, setNum, 0.0f);
	D3DXMatrixTranslation(&matT, pos.x, pos.y, 0);

	// static float fAngle = 0.0f;
	// fAngle += 0.01f;
	// D3DXMatrixRotationZ(&matR, fAngle);

	matWorld = matS * matT;
	m_pSprite->SetTransform(&matWorld);

	m_pSprite->Draw(m_pTextureUI,
		NULL,
		&D3DXVECTOR3(0, 0, 0),
		&D3DXVECTOR3(0, 0, 0),
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
		if (m_isLBtnPush)
		{
			nowPos.x = LOWORD(lParam);
			nowPos.y = HIWORD(lParam);

			m_movePos.x = nowPos.x - m_prevMousPos.x;
			m_movePos.y = nowPos.y - m_prevMousPos.y;

			// m_prevMousPos = m_movePos;
		}
	}
	break;

	}
}
