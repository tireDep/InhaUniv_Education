#pragma once
class cCubePC; 
class cCamera; 
class cGrid; 
class cCubeMan; 
class DirectionLight;
class SpotLight;
class PointLight;

class cGroup;

class cFrame;

class cMtlTex;

class CXfileObj;

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

	iMap *m_pMap;

	cFrame* m_pRootFrame;

	// >> mesh
	LPD3DXMESH m_pMeshTeaPot;
	LPD3DXMESH m_pMeshSphere;
	D3DMATERIAL9 m_stMtlTeaPot;
	D3DMATERIAL9 m_stMtlSphere;

	LPD3DXMESH m_pObjMesh;
	vector<cMtlTex*> m_vecObjMtlTex;
	// << mesh

	// >> piking
	vector<ST_SPHERE> m_vecSphere;
	D3DMATERIAL9 m_stMtlNone;
	D3DMATERIAL9 m_stMtlPicked;
	D3DMATERIAL9 m_stMtlPlane;	// �ٴ�
	vector<ST_PN_VERTEX> m_vecPlanVertex;	// �ٴ�
	D3DXVECTOR3 m_vPickedPosition;	// ���� ���� ��ġ
	// << piking
	
	CXfileObj* m_xFileObj;

public :
	void Setup(); 
	void Update(); 
	void Render(); 
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); 

	void Set_Light(); 

	void Draw_Texture(); 

	void SetUp_Obj();
	void Render_Obj();

	void Load_Surface();

	// >> mesh
	void SetUp_MeshObj();
	void Render_MeshObj();
	// << mesh

	// >> piking
	void SetUp_PickingObj();
	void PickingObj_Render();
	// << piking

};

