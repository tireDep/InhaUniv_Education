
struct LightDesc
{
    float4 Ambient; 
    float4 Specular; 
    float3 Direction; 
    float Padding; 
    float3 Position; 
    float Padding2;
};

cbuffer CB_Light
{
    LightDesc GlobalLight; 
};

struct MaterialDesc
{
    float4 Ambient;
    float4 Diffuse;
    float4 Specular;
};

cbuffer CB_Material
{
    MaterialDesc Material;
};
