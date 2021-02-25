#include "Framework.h"	// << : 
#include "Terrain.h"

Terrain::Terrain(Shader * shader, wstring heightMap) : 
	shader(shader),
	pass(1),
	baseMap(NULL),
	spacing(3,3)
{
	this->heightMap = new Texture(heightMap); 

	CreateVertexData(); 
	CreateIndexData(); 
	CreateNormalData(); 
	CreateBuffer(); 

	sBaseMap = shader->AsSRV("BaseMap");

	D3DXMatrixIdentity(&world);
}

Terrain::~Terrain()
{
	SafeDelete(heightMap); 
	SafeDeleteArray(vertices); 
	SafeDeleteArray(indices); 

	SafeDelete(vertexBuffer); 
	SafeDelete(indexBuffer); 
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
			// >> y좌표 뒤집음
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
	vertexBuffer = new VertexBuffer(vertices, vertexCount, sizeof(TerrainVertex));

	// : create index buffer 
	indexBuffer = new IndexBuffer(indices, indexCount);
}

void Terrain::Update()
{
	shader->AsMatrix("World")->SetMatrix(world);
	shader->AsMatrix("View")->SetMatrix(Context::Get()->View());
	shader->AsMatrix("Projection")->SetMatrix(Context::Get()->Projection());
}

void Terrain::Render()
{
	vertexBuffer->Render();
	indexBuffer->Render();

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
	// >> 1.0f는 칸 크기

	Vector3 temp;
	if (ddx + ddz <= 1)
	{
		// 좌하단
		temp = v[0] + (v[2] - v[0]) *ddx + (v[1] - v[0]) * ddz;
	}
	else
	{
		// 우상단
		ddx = 1 - ddx;
		ddz = 1 - ddz;

		temp = v[3] + (v[1] - v[3]) *ddx + (v[2] - v[3]) * ddz;
	}

	return temp.y;
}

float Terrain::GetPickedHeight(Vector3 & position)
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

	Vector3 p[4];
	for (int i = 0; i < 4; i++)
	{
		p[i] = vertices[index[i]].Position;
	}

	float u, v, distance;

	Vector3 start(position.x, 1000, position.z);
	Vector3 direction(0, -1, 0);

	Vector3 result(-1, -1, -1);


	// 좌하단
	if (D3DXIntersectTri(&p[0], &p[1], &p[2], 
		&start, &direction, &u, &v, &distance) == true)
	{
		result = p[0] + (p[1] - p[0]) * u + (p[2] - p[0])*v;
	}

	// 우상단
	if (D3DXIntersectTri(&p[3], &p[1], &p[2],
		&start, &direction, &u, &v, &distance) == true)
	{
		result = p[3] + (p[1] - p[3]) * u + (p[2] - p[3])*v;
	}

	return result.y;
}

Vector3 Terrain::GetPickedPosition()
{
	Vector3 start, direction;
	Matrix V = Context::Get()->View();
	Matrix P = Context::Get()->Projection();
	// 1안
	// Context::Get()->GetViewport()->GetRay(&start, &direction, world, V, P);

	// 2안
	// 1안보다 속도 개선이 됨
	Vector3 mouse = Mouse::Get()->GetPosition();
	Vector3 n, f;

	mouse.z = 0.0f;
	Context::Get()->GetViewport()->Unproject(&n, mouse, world, V, P);	// 가장 가까운 면

	mouse.z = 1.0f;
	Context::Get()->GetViewport()->Unproject(&f, mouse, world, V, P);	// 가장 멀리있는 면

	direction = f - n;
	start = n;

	for(UINT z = 0; z < height - 1; z++)
	{
		for (UINT x = 0; x < width - 1; x++)
		{
			UINT index[4];
			index[0] = width * (z + 0) + (x + 0);
			index[1] = width * (z + 1) + (x + 0);
			index[2] = width * (z + 0) + (x + 1);
			index[3] = width * (z + 1) + (x + 1);

			Vector3 p[4]; 
			for (int i = 0; i < 4; i++)
			{
				p[i] = vertices[index[i]].Position;
			}

			// 좌상단
			float u, v, distance;
			if (D3DXIntersectTri(&p[0], &p[1], &p[2],
				&start, &direction, &u, &v, &distance) == true)
				return p[0] + (p[1] - p[0]) * u + (p[2] - p[0]) * v;

			// 우하단
			if (D3DXIntersectTri(&p[3], &p[1], &p[2],
				&start, &direction, &u, &v, &distance) == true)
				return p[3] + (p[1] - p[3]) * u + (p[2] - p[3]) * v;
		}
	}

	return Vector3(-1, -1, -1);
}
