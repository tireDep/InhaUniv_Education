#include "Framework.h"
#include "ModelRenderer.h"
#include "ModelMesh.h"

ModelRenderer::ModelRenderer(Shader* shader, Model* model) 
	: model(model)
{
	transform = new Transform();
	for (ModelMesh* mesh : model->Meshes())
		mesh->SetShader(shader);

	UpdateTransform();
}


ModelRenderer::~ModelRenderer()
{
	SafeDelete(transform);
}

void ModelRenderer::Update()
{
	for (ModelMesh* mesh : model->Meshes())
		mesh->Update();
}

void ModelRenderer::Render()
{
	for (ModelMesh* mesh : model->Meshes())
	{
		mesh->SetTransform(transform);
		mesh->Render();
	}
}

void ModelRenderer::Pass(UINT pass)
{
	for (ModelMesh* mesh : model->Meshes())
		mesh->Pass(pass);
}

void ModelRenderer::UpdateTransform(ModelBone * bone, Matrix & matrix)
{
	if (bone != NULL)
		UpdateBones(bone, matrix);

	Matrix boneTransforms[MAX_MODEL_TRANSFORMS];

	for (UINT i = 0; i < model->BoneCount(); i++)
	{
		ModelBone* bone = model->BoneByIndex(i);

		Matrix parentTransform;
		int parentIndex = bone->ParentIndex();
		if (parentIndex < 0)
			D3DXMatrixIdentity(&parentTransform);
		else
			parentTransform = boneTransforms[parentIndex];

		Matrix matrix = bone->Transform();
		boneTransforms[i] = parentTransform;
		renderTransforms[i] = matrix*boneTransforms[i];
	}

	for (ModelMesh* mesh : model->Meshes())
		mesh->Transforms(renderTransforms);
}

void ModelRenderer::UpdateBones(ModelBone * bone, Matrix & matrix)
{
	Matrix temp = bone->Transform();
	bone->Transform(temp * matrix);

	for (ModelBone* child : bone->Childs())
		UpdateBones(child, matrix);
}
