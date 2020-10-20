#pragma once
class CSphere
{
private:
	D3DXVECTOR3 m_center;
	LPD3DXMESH m_pMeshSphere;
	D3DMATERIAL9 m_stMtlSphere;

	bool m_isClicked;

public:
	CSphere();
	~CSphere();

	void SetUp(float radius, UINT slice, UINT stack, D3DXVECTOR3 center);
	void Render();

	void SetIsClicked(bool set);
	void SetMatWorldPos(D3DXVECTOR3 set);

	bool GetIsClicked();
	D3DXVECTOR3 GetCenter();
	D3DXMATRIXA16 GetMatWorld();
	LPD3DXMESH GetMesh();
};

