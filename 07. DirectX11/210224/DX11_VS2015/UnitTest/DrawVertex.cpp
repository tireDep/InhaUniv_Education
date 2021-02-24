#include "stdafx.h"
#include "DrawVertex.h"
#include "Viewer\FreeCam.h"	// << : 

void DrawVertex::Initialize()
{
	//((FreeCam*)Context::Get()->GetCamera())->Speed(40, 10); 
	shader = new Shader(L"004_Quad.fx"); 

	// >> : vertex buffer 
	vertexCount = (width + 1) * (height + 1); 
	vertices = new Vertex[vertexCount]; 

	for (UINT z = 0; z <= height; z++)
	{
		for (UINT x = 0; x <= width; x++)
		{
			UINT index = (width + 1)* z + x; 
			vertices[index].Position.x = (float)x; 
			vertices[index].Position.y = 0.0f; 
			vertices[index].Position.z = (float)z; 
		}
	}
	
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(Vertex) * vertexCount;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = vertices;

		Check(D3D::GetDevice()->CreateBuffer(&desc,
			&subResource,
			&vertexBuffer));
	}
	// << : 

	// >> : index buffer 
	{
		indexCount = width * height * 6; 
		indices = new UINT[indexCount]; 

		UINT index = 0; 
		for (UINT z = 0; z < height; z++)
		{
			for (UINT x = 0; x < width; x++)
			{
				indices[index + 0] = (width + 1) * z + x; 
				indices[index + 1] = (width + 1) * (z + 1) + x;
				indices[index + 2] = (width + 1) * z + x + 1;

				indices[index + 3] = (width + 1) * z + x + 1;
				indices[index + 4] = (width + 1) * (z + 1) + x;
				indices[index + 5] = (width + 1) * (z + 1) + x + 1;

				index += 6; 
			}
		}

		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(UINT) * indexCount;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = indices;
		Check(D3D::GetDevice()->CreateBuffer(&desc,
			&subResource,
			&indexBuffer));
	}				
	// << : 

	color = Color(0, 0, 0, 1); 
}


void DrawVertex::Destroy()
{
	SafeDelete(shader); 
	SafeRelease(vertexBuffer); 
	SafeRelease(indexBuffer); 
}

void DrawVertex::Update()
{
	ImGui::ColorEdit3("Color", (float*)&color); 
	shader->AsVector("Color")->SetFloatVector(color); 

	Matrix world; 
	D3DXMatrixIdentity(&world); 

	//{
	//	static Vector3 position(0, 0, 0);
	//	if (Keyboard::Get()->Press(VK_LEFT))
	//		position.x -= 1.0f * Time::Delta();
	//	else if (Keyboard::Get()->Press(VK_RIGHT))
	//		position.x += 1.0f * Time::Delta();

	//	D3DXMatrixTranslation(&world, position.x, position.y, position.z);
	//}
	D3DXMatrixScaling(&world, 10, 1, 10); 
	shader->AsMatrix("World")->SetMatrix(world); 
	
	Matrix view = Context::Get()->View(); 
	shader->AsMatrix("View")->SetMatrix(view); 

	Matrix projection = Context::Get()->Projection(); 
	shader->AsMatrix("Projection")->SetMatrix(projection); 

}

void DrawVertex::Render()
{
	UINT stride = sizeof(Vertex); 
	UINT offset = 0; 

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer,
		&stride, &offset); 
	D3D::GetDC()->IASetIndexBuffer(indexBuffer,
		DXGI_FORMAT_R32_UINT, 0); 

	D3D::GetDC()->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	static bool b = false; 
	ImGui::Checkbox("Wireframe", &b); 
	shader->DrawIndexed(0, (b ? 0 : 1), indexCount);
}

