#pragma once
class CSphere
{
private:
	LPD3DXMESH m_Mesh;

public:
	CSphere();
	~CSphere();

	void SetUp();
	void Render();
};

