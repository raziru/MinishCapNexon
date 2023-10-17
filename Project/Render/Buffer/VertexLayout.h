#pragma once
struct Vertex
{
	Vector3 pos = {};
};

struct VertexColor
{
	VertexColor(float x, float y)
	{
		pos.x = x;
		pos.y = y;
		pos.z = 0.0f;
	}

	VertexColor(XMFLOAT3 pos, XMFLOAT4 color)
		:pos(pos), color(color)
	{

	}
	XMFLOAT3 pos = {};
	XMFLOAT4 color = {};
};


struct VertexTexture
{
	VertexTexture()
	{
		
	}

	VertexTexture(Vector3 pos, Vector2 uv)
		:pos(pos), uv(uv)
	{

	}
	Vector3 pos = {};
	Vector2 uv  = {};
};
