#pragma once
class cCharacter
{
public:
	cCharacter();
	//~cCharacter();
protected :
	float			m_fRotY; 
	D3DXVECTOR3		m_vDirection; 
	D3DXVECTOR3		m_vPosition; 
	D3DXMATRIXA16	m_matWorld;

	vector<ST_PNT_VERTEX> m_vecMap;

public : 
	virtual ~cCharacter(void); 

	virtual void Setup(); 
	virtual void Update();
	virtual void Update(iMap *pMap);
	virtual void Update_Sub(vector<ST_PC_VERTEX> path, int &destNum);
	virtual void Render(); 
	virtual D3DXVECTOR3& GetPosition(); 

	void SetMap(vector<ST_PNT_VERTEX> set);

	bool Collision_Btm(D3DXVECTOR3 center);

};

