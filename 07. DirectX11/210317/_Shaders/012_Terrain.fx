
#include "000_Header.fx"
#include "000_Light.fx"
#include "000_Terrain.fx"

Texture2D BaseMap;

struct VertexOutput
{
    float4 Position : SV_Position0;
    float3 Normal : Normal0;
    float2 Uv : Uv0;
    float4 wPosition : Position1;
};

VertexOutput VS(VertexTextureNormal input)
{
    VertexOutput output;

    output.Position = WorldPosition(input.Position);
    output.wPosition = output.Position;

    output.Position = ViewProjection(output.Position);
    output.Normal = WorldNormal(input.Normal);

    output.Uv = input.Uv;

    return output;
}

RasterizerState RS
{
    FillMode = Wireframe;
};

float4 PS(VertexOutput input) : SV_Target0
{
    float4 diffuse = BaseMap.Sample(LinearSampler, input.Uv);
    float3 normal = normalize(input.Normal);
    float NdotL = saturate(dot(normal, -GlobalLight.Direction));

    // 0305
    float3 gridColor = GetLineColor(input.wPosition.xyz);
    // return diffuse * NdotL + float4(gridColor, 1);
    return float4(gridColor, 1);
}

technique11 T0
{
    pass P0
    {
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
    }

    pass P1
    {
        SetRasterizerState(RS);
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
    }
}