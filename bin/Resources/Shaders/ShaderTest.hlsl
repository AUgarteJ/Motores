cbuffer cbTest : register(b0)
{
  matrix View;
  matrix Proj;
  matrix World;
};

struct VS_INPUT
{
  float4 Pos : POSITION0;
  //float2 Tex : TEXCOORD0;
};

struct PS_INPUT
{
  float4 Pos : SV_Position;
  //float2 Tex : TEXCOORD0;
};

PS_INPUT VS_Main(VS_INPUT input)
{
  PS_INPUT output = (PS_INPUT)0;
  output.Pos = input.Pos;
/*
  output.Pos = mul(input.Pos, World);
  output.Pos = mul(output.Pos, View);
  output.Pos = mul(output.Pos, Proj);
  //output.Tex = input.Tex;
*/
  return output;
}

float4 PS_Main(PS_INPUT input) : SV_Target
{
	return float4 (1.f, 0.f, 0.f, 1.f);
}
