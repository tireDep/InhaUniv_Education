#pragma once
class ModelRenderer
{
public:
	ModelRenderer(Shader* shader, Model* model);
	~ModelRenderer();

private:
	Model* model;
	Transform* transform;
	Matrix renderTransforms[MAX_MODEL_TRANSFORMS];

public:
	void Update();
	void Render();

	Transform* GetTransform() { return transform; }
	Model* GetModel() { return model; }

	void Pass(UINT pass);

	void UpdateTransform(ModelBone* bone = NULL, Matrix& matrix = Matrix());

private:
	void UpdateBones(ModelBone* bone, Matrix& matrix);
};

