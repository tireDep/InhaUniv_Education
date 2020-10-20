#pragma once

struct ST_RAY
{
	D3DXVECTOR3 vRayOrigin;
	D3DXVECTOR3 vRayDir;
};

class CSphere;

class CMouse
{
private:
	POINT m_clickPos;
	ST_RAY m_ray;

	bool m_isLDown;
	bool m_isRDown;

	D3DXVECTOR3 m_vLookAt;

public:
	CMouse();
	~CMouse();

	void SetUp();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void Update(vector<CSphere *>& mesh, D3DXVECTOR3 setLookAt);
	void CheckClicked(CSphere* mesh, POINT& pos);
};

