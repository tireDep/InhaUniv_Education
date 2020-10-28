#pragma once
class C_UI
{
protected:
	// D3DXVECTOR3 m_anchor;
	// D3DXVECTOR3 m_pivot;

	LPD3DXSPRITE m_pSprite;
	D3DXIMAGE_INFO m_stImgInfo;
	LPDIRECT3DTEXTURE9 m_pTextureUI;

	D3DXMATRIXA16 m_matWorld;

	vector<C_UI*> m_vecCharUI;

	POINT m_movePos;
	POINT m_prevMousPos;
	bool m_isLBtnPush;

	bool m_isUI;

public:
	C_UI();
	~C_UI();

	void SetUp(char* szFolder, char* szFile);
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

