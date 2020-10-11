#pragma once
class cCubePC; 
class cCamera; 
class cGrid; 
class cCubeMan; 
class DirectionLight;
class SpotLight;
class PointLight;

class cGroup;

class cPath;

#include "cLight.h"

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

	DirectionLight* m_directLight;
	SpotLight* m_SpotLight;
	PointLight* m_PointLight;

	vector<cLight *> m_vecLight;

	// >> : for texture 
	LPDIRECT3DTEXTURE9		m_pTexture; 
	vector<ST_PT_VERTEX>	m_vecVertex; 
	// << :

	vector<cGroup*> m_vecGroup;

	vector<cPath*> m_vecPath;

public :
	void Setup(); 
	void Update(); 
	void Render(); 
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 

	void Set_Light(); 

	void Draw_Texture(); 

	void SetUp_Obj();
	void Render_Obj();
};

