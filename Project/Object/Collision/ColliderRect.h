#pragma once
class ColliderRect:public Collider
{
public:
	ColliderRect(Vector2 size);
	~ColliderRect();

	void SetVertex() override;

	bool Collision(Vector2 point) override;

	bool Collision(ColliderRect* rect) override;

	bool Collision(ColliderCircle* other) override;

	Vector2 Size() { return Vector2(size.x * globalScale.x, size.y * globalScale.y); }

private:


	// Collider��(��) ���� ��ӵ�
	Vector2 size = {};

};



