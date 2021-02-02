#include "stdafx.h"
#include "DrawVertex.h"

void DrawVertex::Initialize()
{
	shader = new Shader(L"004_Quad.fx");

	//vertices[0].Position = Vector3(-0.5f, 0.0f, -0.5f);
	//vertices[1].Position = Vector3(-0.5f, 0.0f, 0.5f);
	//vertices[2].Position = Vector3(0.5f, 0.0f, -0.5f);
	//
	//vertices[3].Position = Vector3(0.5f, 0.0f, -0.5f);
	//vertices[4].Position = Vector3(-0.5f, 0.0f, 0.5f);
	//vertices[5].Position = Vector3(0.5f, 0.0f, 0.5f);

	vertices[0].Position = Vector3(-0.5f, 0.0f, -0.5f);
	vertices[1].Position = Vector3(-0.5f, 0.0f,  0.5f);
	vertices[2].Position = Vector3( 0.5f, 0.0f, -0.5f);
	vertices[3].Position = Vector3( 0.5f, 0.0f,  0.5f);

	// << : vertexBuffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(Vertex) * 4;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		
		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = vertices;
		
		Check(D3D::GetDevice()->CreateBuffer(&desc,
											&subResource,
											&vertexBuffer));
	}
	// >> : vertexBuffer

	// << : indexBuffer
	{
		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;

		indices[3] = 2;
		indices[4] = 1;
		indices[5] = 3;

		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(UINT) * 6;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = indices;

		Check(D3D::GetDevice()->CreateBuffer(&desc,
			&subResource,
			&indexBuffer));
	}
	// >> : indexBuffer

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

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);

	D3D::GetDC()->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	static bool b = false;
	ImGui::Checkbox("Wireframe", &b);

	// shader->Draw(0, (b? 0 : 1), 6);
	shader->DrawIndexed(0, (b ? 0 : 1), 6);
}
