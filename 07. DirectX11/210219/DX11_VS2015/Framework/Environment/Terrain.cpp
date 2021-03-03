#include "Framework.h"	// << : 
#include "Terrain.h"

Terrain::Terrain(Shader * shader, wstring heightMap) : 
	shader(shader),
	pass(0),
	baseMap(NULL),
	spacing(3,3)
{
	this->heightMap = new Texture(heightMap); 

	CreateVertexData(); 
	CreateIndexData(); 
	CreateNormalData(); 
	CreateBuffer(); 

	sBaseMap = shader->AsSRV("BaseMap");
}

Terrain::~Terrain()
{
	SafeDelete(heightMap); 
	SafeDeleteArray(vertices); 
	SafeDeleteArray(indices); 

	SafeRelease(vertexBuffer); 
	SafeRelease(indexBuffer); 
}

void Terrain::CreateVertexData()
{
	vector<Color>	heights; 
	heightMap->ReadPixels(DXGI_FORMAT_R8G8B8A8_UNORM, &heights); 

	width = heightMap->GetWidth(); 
	height = heightMap->GetHeight(); 

	vertexCount = width * height; 
	vertices = new TerrainVertex[vertexCount]; 

	for (UINT z = 0; z < height; z++)
	{
		for (UINT x = 0; x < width; x++)
		{
			UINT index = width * z + x; 
			UINT pixel = width * (height - 1 - z) + x;

			vertices[index].Position.x = (float)x; 
			vertices[index].Position.y = heights[pixel].r * 255.0f / 10.0f;
			vertices[index].Position.z = (float)z;

			// vertices[index].Uv.x = ((float)x / (float)width);
			vertices[index].Uv.x = ((float)x / (float)width) * spacing.x;
			vertices[index].Uv.y = ((float)(height - 1 - z) / (float)height) * spacing.y;
			// >> y��ǥ ������
		}
	}
}

void Terrain::CreateIndexData()
{
	indexCount = (width - 1) * (height - 1) * 6; 
	indices = new UINT[indexCount]; 

	UINT index = 0; 
	for (UINT z = 0; z < height - 1; z++)
	{
		for (UINT x = 0; x < width - 1; x++)
		{
			indices[index + 0] = width * z		+ x; 
			indices[index + 1] = width * (z+1)	+ x;
			indices[index + 2] = width * z		+ x+1;

			indices[index + 3] = width * z		+ x+1;
			indices[index + 4] = width * (z+1)	+ x;
			indices[index + 5] = width * (z+1)	+ x+1;

			index += 6; 
		}
	}
}

void Terrain::CreateNormalData()
{
	for (UINT i = 0; i < indexCount / 3; i++)
	{
		UINT index0 = indices[i * 3 + 0]; 
		UINT index1 = indices[i * 3 + 1];
		UINT index2 = indices[i * 3 + 2];

		TerrainVertex	v0 = vertices[index0]; 
		TerrainVertex	v1 = vertices[index1];
		TerrainVertex	v2 = vertices[index2];

		Vector3 d1 = v1.Position - v0.Position; 
		Vector3 d2 = v2.Position - v0.Position;

		Vector3 normal; 
		D3DXVec3Cross(&normal, &d1, &d2); 

		vertices[index0].Normal += normal; 
		vertices[index1].Normal += normal;
		vertices[index2].Normal += normal;
	}

	for (UINT i = 0; i < vertexCount; i++)
		D3DXVec3Normalize(&vertices[i].Normal, &vertices[i].Normal); 

}

void Terrain::CreateBuffer()
{
	// : create vertex buffer 
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(TerrainVertex) * vertexCount;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA data = { 0 };
		data.pSysMem = vertices;

		Check(D3D::GetDevice()->CreateBuffer(&desc,
			&data,
			&vertexBuffer));
	}

	// : create index buffer 
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(UINT) * indexCount;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		D3D11_SUBRESOURCE_DATA data = { 0 };
		data.pSysMem = indices;
		Check(D3D::GetDevice()->CreateBuffer(&desc,
			&data,
			&indexBuffer));
	}
}

void Terrain::Update()
{
	Matrix world;
	D3DXMatrixIdentity(&world);
	shader->AsMatrix("World")->SetMatrix(world);
	shader->AsMatrix("View")->SetMatrix(Context::Get()->View());
	shader->AsMatrix("Projection")->SetMatrix(Context::Get()->Projection());
}

void Terrain::Render()
{
	UINT stride = sizeof(TerrainVertex);
	UINT offset = 0;

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer,&stride, &offset);
	D3D::GetDC()->IASetIndexBuffer(indexBuffer,	DXGI_FORMAT_R32_UINT, 0);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	shader->DrawIndexed(0, pass, indexCount);
}

void Terrain::BaseMap(wstring file)
{
	SafeDelete(baseMap);
	baseMap = new Texture(file);
	sBaseMap->SetResource(baseMap->SRV());
}

float Terrain::GetHeight(Vector3 & position)
{
	UINT x = (UINT)position.x;
	UINT z = (UINT)position.z;

	if (x < 0 || x > width)
		return -1.0f;
	if (z < 0 || z > height)
		return -1.0f;

	UINT index[4];
	index[0] = width * (z + 0) + (x + 0);
	index[1] = width * (z + 1) + (x + 0);
	index[2] = width * (z + 0) + (x + 1);
	index[3] = width * (z + 1) + (x + 1);

	Vector3 v[4];
	for (int i = 0; i < 4; i++)
	{
		v[i] = vertices[index[i]].Position;
	}

	float ddx = (position.x - v[0].x) / 1.0f;
	float ddz = (position.z - v[0].z) / 1.0f;	
	// >> 1.0f�� ĭ ũ��

	Vector3 temp;
	if (ddx + ddz <= 1)
	{
		// ���ϴ�
		temp = v[0] + (v[2] - v[0]) *ddx + (v[1] - v[0]) * ddz;
	}
	else
	{
		// ����
		ddx = 1 - ddx;
		ddz = 1 - ddz;

		temp = v[3] + (v[1] - v[3]) *ddx + (v[2] - v[3]) * ddz;
	}

	return temp.y;
}