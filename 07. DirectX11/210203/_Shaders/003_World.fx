matrix World;
matrix View;
matrix Projection;

float3 Color;

struct VertexInput
{
	float4 Position : Position0;
};

struct VertexOutput
{
	float4 Position : SV_Position0;
};

VertexOutput VS(VertexInput input)
{
	VertexOutput output;

    output.Position = mul(input.Position, World);
    output.Position = mul(output.Position, View);
    output.Position = mul(output.Position, Projection);
	
	return output;
}

float4 PS(VertexOutput input) : SV_Target0
{
    return float4(Color.x, Color.y, Color.z, 1);
}

technique11 T0
{
	pass P0
	{
		SetVertexShader(CompileShader(vs_5_0, VS()));
		SetPixelShader(CompileShader(ps_5_0, PS()));
	}

}