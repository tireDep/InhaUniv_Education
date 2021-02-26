#include "000_Header.fx"

float2 Uv;

struct VertexOutput
{
	float4 Position : SV_Position0; 
	float2 Uv : Uv0;
};

VertexOutput VS(VertexTexture input)
{
	VertexOutput output; 
    output.Position = WorldPosition(input.Position);
    output.Position = ViewProjection(output.Position);
    output.Uv = input.Uv;

	return output; 
}

float4 PS(VertexOutput input) : SV_Target0 
{
    // 범위보다 작으면 검정처리
    // flatten <-> branch
    // flatten : 계산 유리
    // branch : 속도 유리

    [flatten]
    if(input.Uv.x < Uv.x)
        return float4(0, 0, 0, 1); 
    
    if (input.Uv.y < Uv.y)
        return float4(0, 0, 0, 1);

    return DiffuseMap.Sample(Sampler, input.Uv);
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