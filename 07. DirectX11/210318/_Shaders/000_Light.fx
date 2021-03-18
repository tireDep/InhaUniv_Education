
// constant buffer는 16 바이트여야함
struct LightDesc
{
    float4 Ambient;
    float4 Specular;
    float3 Direction;
    float Padding;      // 의미 없는 변수, 16 바이트 맞춰주는 용도
    float3 Position;
    // 배열형식으로 쓸 경우 Position에도 Padding 변수가 필요해짐
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