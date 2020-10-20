#pragma once

// class CMouse;

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

	iMap *m_pMap;

	D3DXVECTOR3(*funcPtr) (D3DXVECTOR3 v);
	D3DXVECTOR3 m_destPos;
	bool m_isMoving;

public : 
	virtual ~cCharacter(void); 

	virtual void Setup(); 
	virtual void Update(iMap *pMap);
	virtual void Render(); 
	virtual D3DXVECTOR3& GetPosition(); 

};

