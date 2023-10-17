#pragma once
class Object : public Transform
{
public:
	Object(Vector2 size);
	Object(wstring file, Vector2 uvStart = Vector2(0, 0), Vector2 uvEnd = Vector2(1, 1));

	~Object();

	void Render();


private:
	vector<VertexTexture> vertices;
	vector<UINT>         indices;

	VertexBuffer* vertexBuffer;
	 IndexBuffer*  indexBuffer;
	VertexShader* vertexShader;

	PixelShader* pixelShader;

	MatrixBuffer* worldBuffer;
	ColorBuffer* colorbuffer;

	Texture* texture = nullptr;

};

