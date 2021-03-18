
#include "000_Header.fx"

Texture2D BaseMap; 

struct VertexOutput
{
	float4 Position : SV_Position0; 
    float3 Normal : Normal0; 
    float2 Uv : Uv0; 
};

VertexOutput VS(VertexTextureNormal input)
{
	VertexOutput output; 
    output.Position = mul(input.Position, World); 
    output.Position = mul(output.Position, View); 
    output.Position = mul(output.Position, Projection); 
    output.Normal = mul(input.Normal, (float3x3) World); 
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
    float NdotL = saturate(dot(normal, -LightDirection));
    return diffuse * NdotL; 
}


SamplerState Address_Wrap
{
    AddressU = WRAP;
    AddressV = WRAP;
};

SamplerState Address_Mirror
{
    AddressU = MIRROR;
    AddressV = MIRROR;
};

SamplerState Address_Clamp
{
    AddressU = CLAMP;
    AddressV = CLAMP;
};

SamplerState Address_Border
{
    AddressU = BORDER;
    AddressV = BORDER;
    BorderColor = float4(0, 0, 1, 1);
};

uint Address;
float4 PS_Address(VertexOutput input) : SV_Target0
{
    [branch]
    switch (Address)
    {
        case 0:
            return DiffuseMap.Sample(Address_Wrap, input.Uv);
        case 1:
            return DiffuseMap.Sample(Address_Mirror, input.Uv);
        case 2:
            return DiffuseMap.Sample(Address_Clamp, input.Uv);
        case 3:
            return DiffuseMap.Sample(Address_Border, input.Uv);
    }
    return float4(0, 0, 0, 1);
}

SamplerState Point
{
    Filter = MIN_MAG_MIP_POINT; 
}; 

SamplerState Linear
{
    Filter = MIN_MAG_MIP_LINEAR;
};

uint Filter; 
float4 PS_Filter(VertexOutput input) : SV_Target0
{
    [branch]
    switch (Filter)
    {
        case 0:
            return DiffuseMap.Sample(Point, input.Uv); 
        case 1:
            return DiffuseMap.Sample(Linear, input.Uv);
    }

    return float4(0, 0, 0, 1); 
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
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS_Address()));
    }

    pass P2
    {
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS_Filter()));
    }
}