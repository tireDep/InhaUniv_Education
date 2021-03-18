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

	// 0305
	Texture*		layerMap;
	ID3DX11EffectShaderResourceVariable* sLayerMap;

	Texture*		alphaMap;
	ID3DX11EffectShaderResourceVariable* sAlphaMap;
	//

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

	// 0305
	void LayerMap(wstring layer, wstring alpha);
	//

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

// 0305
private:
	struct LineColorDesc
	{
		Color Color = D3DXCOLOR(1, 1, 1, 1);
		UINT Visible = 1;
		float Thickness = 0.1f;
		float Size = 1;
		float Padding;
	}lineColorDesc;

	ConstantBuffer* lineColorBuffer;
	ID3DX11EffectConstantBuffer* sLineColorBuffer;
};

