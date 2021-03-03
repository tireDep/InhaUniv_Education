#pragma once
class Terrain
{
public:
	Terrain(Shader* shader , wstring heightMap);
	~Terrain();

public : 
	typedef VertexNormal	TerrainVertex; 

private:
	Shader* shader; 

	Texture*	heightMap; 
	UINT		width, height; 
	UINT		pass; 

	UINT			vertexCount; 
	TerrainVertex*	vertices; 
	ID3D11Buffer*	vertexBuffer; 

	UINT			indexCount; 
	UINT*			indices; 
	ID3D11Buffer*	indexBuffer; 

private :
	void CreateVertexData(); 
	void CreateIndexData(); 
	void CreateNormalData(); 
	void CreateBuffer(); 

public :
	void Update(); 
	void Render(); 
};
