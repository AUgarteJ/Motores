

float4 VS_Main(float4 pos : POSITION) : SV_POSITION
{
  return pos;
}

float PS_Main(float4 Pos : SV_POSITION ) : SV_Target
{
	return float4 (1.f, 0.f, 0.f, 1.f);
}
