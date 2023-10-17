#pragma once
class Transform
{
public:
	Transform();
	virtual ~Transform();

	virtual void Update();

	void UpdateWorld();

	void SetParent(Transform* parent) { this->parent = parent; }

	Matrix GetWorld() { return world; }

	Matrix GetT() { return T; }

	void Debug();

	void SetLabel(string label) { this->label = label; }

	void SetPivot(Vector2 pivot) { this->pivot = pivot; }

	Vector2 GlobalScale()   { return globalScale; }
	Vector2 GlobalPostion() { return globalPosition; }

	bool& IsActive() { return isActive; }

	string GetLabel() { return label; }


public:
	Vector2 scale       = {1.0f , 1.0f };
	Vector3 rotation   =  {0.0f , 0.0f, 0.0f };
	Vector2 translation = {0.0f , 0.0f };
	

protected:

	Matrix S, R, T;	

	Matrix world;

	Transform* parent = nullptr;

	Vector2 pivot = {};

	bool isActive = true;

	string label;

	Vector2 globalScale;
	Vector2 globalPosition;

	Vector2 right, up;
};


