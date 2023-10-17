cbuffer ColorBuffer : register(b0)
{
    float4 color;
}

struct VertexOutput
{
    float4 pos : SV_POSITION;
};

float4 main(VertexOutput input) : SV_TARGET
{
    return color;
}