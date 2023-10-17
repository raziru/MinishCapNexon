#pragma once
class Actor : public Transform
{
public:
	Actor();
	virtual ~Actor();

	virtual void Update();
	virtual void Render();

	void SetAction(int state);

	

	Vector2 GetSize()
	{
		return Vector2(
			curAction->Size().x * globalScale.x,
			curAction->Size().y * globalScale.y
		);
	}

	virtual void AddAction() = 0;
	Collider* BodyCollider() { return bodyCollider; }

protected:

	VertexShader* vertexShader;
	 PixelShader* pixelShader;

	MatrixBuffer* worldBuffer;
	 ColorBuffer* colorBuffer;

	map<int, Animation*> actions;

	Animation* curAction = nullptr;

	int state = 0;

	float moveSpeed = 0.0f;
	Vector2 moveDir = {};

	Collider* bodyCollider = nullptr;
	wstring file;


	enum Direct
	{
		FORWARD,
		RIGHT,
		LEFT,
		BACK
	};
};


