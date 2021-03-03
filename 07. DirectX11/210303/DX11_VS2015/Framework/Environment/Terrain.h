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

// 0303
private:
	struct BrushDesc
	{
		Color color = D3DXCOLOR(0, 1, 0, 1);
		Vector3 location;
		UINT type = 0;	// 그리는 번호
		UINT range = 1;	// 편집 범위

		float padding[3];
	}brushDesc;

	ConstantBuffer* brushBuffer;
	ID3DX11EffectConstantBuffer* sBrushBuffer;

public:
	void RaiseHeight(Vector3& position, UINT type, UINT range);

};

