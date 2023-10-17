#pragma once
class ColliderCircle:public Collider
{
public:
	ColliderCircle(float radius);
	~ColliderCircle();

	virtual void SetVertex() override;

	virtual bool Collision(Vector2 point) override;
	virtual bool Collision(ColliderRect* other) override;
	virtual bool Collision(ColliderCircle* other) override;

	float Radius() { return radius * max(globalScale.x, globalScale.y); }

private:

	float radius = 0.0f;

	const UINT VERTEX_COUNT = 36;
	

};



