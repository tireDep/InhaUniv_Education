#pragma once

class CFrustumObj
{
private:
	vector<D3DXPLANE> m_vecPlane;

public:
	CFrustumObj();
	~CFrustumObj();

	void SetUp();
	void Update();
	bool IsInFrustum(D3DXVECTOR3 vPoint, float& fRadius, bool isClicked);
	void Render();
};

