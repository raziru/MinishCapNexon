#pragma once
class Zelda:public Actor
{
	enum State
	{
		IDLE,
		WALK,
		DAMAGED,
		PRAY,
		DEAD,
	};
	enum AnimState
	{
		IDLE_FORWARD,
		IDLE_SIDE,
		IDLE_BACK,
		WALK_FORWARD,
		WALK_SIDE,
		WALK_BACK,
		DAMAGED_FORWARD,
		DAMAGED_SIDE,
		DAMAGED_BACK,
		ANIM_PRAY,
		ANIM_DEAD,
	};



public:
	Zelda();
	~Zelda();

	virtual void Update();

	void SetState(State state) { this->state = state; }

	void SetDirection(Direct direct);

	void Idle();

	void Walk();

	void Damaged();

private:


	// Character을(를) 통해 상속됨
	void AddAction() override;


	Direct direct = FORWARD;

	State state = IDLE;
	bool isAttack = false;

};



