#pragma once
class Camera:public Singleton<Camera>
{
public:
	Camera();
	~Camera();

	void Update();
	void Set();

	void   FreeMode();
	void TargetMode();

	void SetTarget(Transform* target) { this->target = target; }

private:
	Transform* transform;

	MatrixBuffer*  viewBuffer;

	Transform* target = nullptr;
	float speed = 100;

	Vector2 offset = WIN_CENTER;
};


