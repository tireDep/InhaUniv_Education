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

float4 PS(VertexOutput input) : SV_Target0 
{
    // return float4(-LightDirection * 0.5f + 0.5f, 1);
    // >> 빛이 들어오는지 간단히 확인해 볼 때

    float4 diffuse = BaseMap.Sample(LinearSampler, input.Uv);
    float3 normal = normalize(input.Normal);
    float NdotL = saturate(dot(normal, -LightDirection));

    return diffuse * NdotL;
}

SamplerState Address_Wrap
{
    AddressU = WRAP;
    AddressU = WRAP;
};

SamplerState Address_Mirror
{
    AddressU = MIRROR;
    AddressU = MIRROR;
};

SamplerState Address_Clamp
{
    AddressU = CLAMP;
    AddressU = CLAMP;
};

SamplerState Address_Border
{
    AddressU = BORDER;
    AddressU = BORDER;
    BorderColor = float4(0, 0, 1, 1);
};

uint Address;
float4 PS_Adress(VertexOutput input) : SV_Target0
{
    // switch 문은 [branch]만 사용 가능

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
    Filter = MIN_MAG_MIP_POINT; // >> 재정의
    // >> 포인트 방식
};

SamplerState Linear
{
    Filter = MIN_MAG_MIP_LINEAR; // >> 재정의
    // >> 선형보간 방식
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

    return float4(1, 0, 0, 0);
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
        SetPixelShader(CompileShader(ps_5_0, PS_Adress()));
    }

    pass P2
    {
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS_Filter()));
    }
}