#include "stdafx.h"
#include "DrawVertex.h"

void DrawVertex::Initialize()
{
	//shader = new Shader(L"001_Vertex.fx");

	//vertices[0].Position = Vector3(0.0f, 0.0f, 0.0f);
	//vertices[1].Position = Vector3(0.0f, 0.5f, 0.0f);

	//vertices[2].Position = Vector3(0.5f, 0.0f, 0.0f);
	//vertices[3].Position = Vector3(0.0f, 0.5f, 0.0f);

	//vertices[4].Position = Vector3(0.5f, 0.0f, 0.0f);
	//vertices[5].Position = Vector3(0.5f, 0.5f, 0.0f);

	//D3D11_BUFFER_DESC desc;
	//ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
	//desc.Usage = D3D11_USAGE_DEFAULT;
	//desc.ByteWidth = sizeof(Vertex) * 6;
	//desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	//
	//D3D11_SUBRESOURCE_DATA subResource = { 0 }; // == ZeroMemory
	//subResource.pSysMem = vertices;
	//
	//Check(D3D::GetDevice()->CreateBuffer(&desc,
	//									&subResource,
	//									&vertexBuffer));

	// Homework
	shader = new Shader(L"001_Vertex.fx");

	vertices[0].Position = Vector3(0.0f, 0.0f, 0.0f);
	vertices[1].Position = Vector3(-0.1f, -0.5f, 0.0f);

	vertices[2].Position = Vector3(-0.1f, -0.5f, 0.0f);
	vertices[3].Position = Vector3(0.15f, -0.2f, 0.0f);

	vertices[4].Position = Vector3(0.15f, -0.2f, 0.0f);
	vertices[5].Position = Vector3(-0.15f, -0.2f, 0.0f);

	vertices[6].Position = Vector3(-0.15f, -0.2f, 0.0f);
	vertices[7].Position = Vector3(0.1f, -0.5f, 0.0f);

	vertices[8].Position = Vector3(0.1f, -0.5f, 0.0f);
	vertices[9].Position = Vector3(0.0f, 0.0f, 0.0f);

	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.ByteWidth = sizeof(Vertex) * 10;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	
	D3D11_SUBRESOURCE_DATA subResource = { 0 }; // == ZeroMemory
	subResource.pSysMem = vertices;
	
	Check(D3D::GetDevice()->CreateBuffer(&desc,
										&subResource,
										&vertexBuffer));
}

void DrawVertex::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
}

void DrawVertex::Update()
{
}

void DrawVertex::Render()
{
	//UINT stride = sizeof(Vertex);	// 간격
	//UINT offset = 0;

	//D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	//// 기본 제공 되는 함수

	//// D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	//D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	//// 어떤 형식으로 그릴 것인지

	//shader->Draw(0, 0, 6);

	// homeWork
	UINT stride = sizeof(Vertex);	// 간격
	UINT offset = 0;

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	// 기본 제공 되는 함수

	// D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	// 어떤 형식으로 그릴 것인지

	shader->Draw(0, 0, 10);
}
