#pragma once
class cCubePC; 
class cCamera; 
class cGrid; 
class cCubeMan; 


class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private :
	cCubePC*		m_pCubePC; 
	cCamera*		m_pCamera; 
	cGrid*			m_pGrid; 

	cCubeMan*		m_pCubeMan; 

	// >> : for texture 
	LPDIRECT3DTEXTURE9		m_pTexture; 
	vector<ST_PT_VERTEX>	m_vecVertex; 
	// << :

public :
	void Setup(); 
	void Update(); 
	void Render(); 
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 

	void Set_Light(); 

	void Draw_Texture(); 
};

