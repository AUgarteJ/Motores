cbuffer cbTest : register(b0)
{
  matrix View;
  matrix Proj;
  matrix World;
};


struct VS_INPUT
{
  float4 Pos : POSITION;
  float2 Tex : TEXCOORD0;
};

struct PS_INPUT
{
  float4 Pos : SV_POSITION;
  float2 Tex : TEXCOORD0;
};

PS_INPUT VS(VS_INPUT input)
{
  PS_INPUT output = (PS_INPUT)0;
  output.Pos = mul(input.Pos, World);
  output.Pos = mul(output.Pos, View);
  output.Pos = mul(output.Pos, Proj);
  output.Tex = input.Tex;

  return output;
}

//float PS(PS_INPUT input) : SV_Target
//{
//  return 
//}

float4 VS_Main(float4 pos : POSITION) : SV_POSITION
{
  return pos;
}

float PS_Main(float4 Pos : SV_POSITION ) : SV_Target
{
	return float4 (1.f, 0.f, 0.f, 1.f);
}
