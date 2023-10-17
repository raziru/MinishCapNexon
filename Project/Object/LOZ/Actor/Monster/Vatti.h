#pragma once
class Vatti:public Monster
{
public:
	Vatti();
	~Vatti();

	void AddAction() override;

	virtual void Update() override;
	virtual void Render() override;

private:

	// Monster을(를) 통해 상속됨

	enum AnimState
	{
		IDLE_FORWARD,
		IDLE_SIDE,
		IDLE_BACK,
		WALK_FORWARD,
		WALK_SIDE,
		WALK_BACK,
		ATTACK_FORWARD,
		ATTACK_SIDE,
		ATTACK_BACK,
		CHARGE_FORWARD,
		CHARGE_SIDE,
		CHARGE_BACK,
		SPIN_TO_FORWARD,
		SPIN_TO_BACK,
		CHANGE_FORM,
		TRANSFORM
	};
	wstring file2;

};

