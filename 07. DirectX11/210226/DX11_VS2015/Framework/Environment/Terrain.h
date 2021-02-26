#pragma once
class Terrain : Renderer
{
public:
	Terrain(Shader* shader , wstring heightMap);
	~Terrain();

public : 
	typedef VertexTextureNormal TerrainVertex;

private:
	Texture*		heightMap; 
	UINT			width, height; 

	TerrainVertex*	vertices; 
	UINT*			indices; 

	Texture*		baseMap;
	ID3DX11EffectShaderResourceVariable* sBaseMap;
	Vector2			spacing;

private :
	void CreateVertexData(); 
	void CreateIndexData(); 
	void CreateNormalData(); 
	void CreateBuffer(); 

public :
	void Update(); 
	void Render(); 

	void BaseMap(wstring file);

	float GetHeight(Vector3& position);

	float GetPickedHeight(Vector3& position);

	Vector3 GetPickedPosition();
};

