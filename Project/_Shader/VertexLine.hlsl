cbuffer World : register(b0)
    //const buffer, shader ���ο����� �ٲ��� �ʴ� ���, b0 �������� �Ѱ��ٶ� �������� ��ġ�� ���� ��������.
{
    matrix world;
}
//layoutbuffer, indexbuffer�ܿ��� ��� const buffer�̴�.

cbuffer View : register(b1)
{
    matrix view;
}

cbuffer Proj : register(b2)
{
    matrix proj;
}

struct VertexInput
{
    float4 pos   : POSITION;
};

struct VertexOutput
{
    float4 pos   : SV_POSITION;
};

VertexOutput main( VertexInput input )
{ 
    VertexOutput output;
    output.pos = mul( input.pos, world);
    output.pos = mul(output.pos, view);
    output.pos = mul(output.pos, proj);
    
    
	return output;
}