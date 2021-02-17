#include "Framework.h"

MeshQuad::MeshQuad(Shader * shader) :
	Mesh(shader)
{
}

MeshQuad::~MeshQuad()
{
}

void MeshQuad::Create()
{
	float w = 0.5f;
	float h = 0.5f;

	vector<MeshVertex> v;

	v.push_back(MeshVertex(-w, -h, 0, 0, 0, -1));
	v.push_back(MeshVertex(-w, h, 0, 0, 0, -1));
	v.push_back(MeshVertex(w, -h, 0, 0, 0, -1));
	v.push_back(MeshVertex(w, h, 0, 0, 0, -1));

	vertexCount = v.size();
	vertices = new MeshVertex[vertexCount];

	copy(v.begin(), v.end(),
		stdext::checked_array_iterator<MeshVertex*>(vertices, vertexCount));

	indexCount = 6;
	indices = new UINT[indexCount]
	{
		0, 1, 2, 2, 1, 3
	};
}