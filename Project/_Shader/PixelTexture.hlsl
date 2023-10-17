cbuffer ColorBuffer : register(b0)
{
    float4 color;
}

struct VertexOutput
{
    float4 pos : SV_POSITION;
    float2 uv  : UV;
};

Texture2D     map : register(t0); //SRV
SamplerState smap : register(s0);


float4 main(VertexOutput input) : SV_TARGET
{
    float4 textureColor = map.Sample(smap,input.uv);
    
    //if (all(textureColor == float4(1, 0, 1, 1)))
    //{
    //    textureColor.a = 0.0f; //discard;
    //}
    
    //if(textureColor.r<0.5f)
    //    discard;
    
	return textureColor * color;
}