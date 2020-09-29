#pragma once
class cCubePNT
{
public:
	cCubePNT();
	//~cCubePNT();
protected :
	std::vector<ST_PNT_VERTEX>	m_vecVertex; 

	// >> : for texture 
	LPDIRECT3DTEXTURE9		m_pTexture;
	vector<ST_PT_VERTEX>	m_vecVertex_t;
	// << :

public :
	virtual ~cCubePNT(void); 
	virtual void Setup(); 
	virtual void Update(); 
	virtual void Render(); 
};

