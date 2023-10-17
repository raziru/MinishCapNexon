#pragma once

class Collider :public Transform
{
public:
	Collider();
	virtual ~Collider();

	void Render();

	virtual void SetVertex() = 0;

	bool Collision(Collider* other);

	virtual bool Collision(      Vector2         point) = 0;
	virtual bool Collision(class ColliderRect*   other) = 0;
	virtual bool Collision(class ColliderCircle* other) = 0;

	void SetColor(float r, float g, float b) { colorBuffer->SetData(Vector4(r, g, b, 1.0f)); }

protected:
	vector<Vertex> vertices;

	VertexBuffer* vertexBuffer;

	VertexShader* vertexShader;
 	PixelShader* pixelShader;

	MatrixBuffer* worldBuffer;
	 ColorBuffer* colorBuffer;
};


