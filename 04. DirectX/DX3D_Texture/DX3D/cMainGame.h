#pragma once
class cCubePC; 
class cCamera; 
class cGrid; 
class cCubeMan; 
class DirectionLight;
class SpotLight;
class PointLight;

#include "cLight.h"
#include "cDirection.h"

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

	cDirection* m_direction;
	cDirection m_NewDirection;

public :
	void Setup(); 
	void Update(); 
	void Render(); 
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 

	void Set_Light(); 

	void Draw_Texture(); 
};

