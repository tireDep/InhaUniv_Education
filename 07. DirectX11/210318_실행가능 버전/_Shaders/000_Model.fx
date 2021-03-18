
#define MAX_MODEL_TRANSFORMS 128

struct VertexModel
{
    float4 Position : Position0;
    float2 Uv : Uv0;
    float3 Normal : Normal0;
};

cbuffer CB_Bone
{
    matrix BoneTransforms[MAX_MODEL_TRANSFORMS];
    uint BoneIndex;
};

void SetModelWorld(inout matrix world, VertexModel input)
{
    world = mul(BoneTransforms[BoneIndex], world);
}