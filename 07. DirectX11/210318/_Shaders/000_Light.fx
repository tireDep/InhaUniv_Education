
// constant buffer�� 16 ����Ʈ������
struct LightDesc
{
    float4 Ambient;
    float4 Specular;
    float3 Direction;
    float Padding;      // �ǹ� ���� ����, 16 ����Ʈ �����ִ� �뵵
    float3 Position;
    // �迭�������� �� ��� Position���� Padding ������ �ʿ�����
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