#pragma once
class C_UI
{
protected:
	LPD3DXSPRITE m_pSprite;
	D3DXIMAGE_INFO m_stImgInfo;
	vector<LPDIRECT3DTEXTURE9> m_vecTextureUI;

	D3DXMATRIXA16 m_matWorld;

	vector<C_UI*> m_vecCharUI;

	POINT m_movePos;
	POINT m_prevMousPos;
	bool m_isLBtnPush;

	bool m_isUI;

	POINT m_center;
	RECT rc;

	POINT m_parentCenter;

	int m_index;

public:
	C_UI();
	~C_UI();

	void SetUp(char* szFolder, char* szFile);
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

