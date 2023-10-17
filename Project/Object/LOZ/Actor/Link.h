#pragma once
class Link:public Actor
{
	
	enum AnimState
	{
		IDLE_FORWARD,
		IDLE_SIDE,
		IDLE_BACK,
		WALK_FORWARD,
		WALK_SIDE,
		WALK_BACK,
		FOLK_FORWARD,
		FOLK_SIDE,
		FOLK_BACK,
		DRAW_FORWARD,
		DRAW_SIDE,
		DRAW_BACK,
		ITEM_BIG,
		ITEM_SMALL,
		RUSH_FORWARD,
		RUSH_SIDE,
		RUSH_BACK,
		CHARGE_FORWARD,
		CHARGE_SIDE,
		CHARGE_BACK,
		DAMAGED_FORWARD,
		DAMAGED_SIDE,
		DAMAGED_BACK,
		SPIN_FORWARD,
		SPIN_SIDE,
		SPIN_BACK,
		ROLL_FORWARD,
		ROLL_SIDE,
		ROLL_BACK,		
		FALL,
		DEAD,
		SLEEP_FORWARD,
		SLEEP_SIDE,
		SLEEP_BACK,

		SLEEPING_FORWARD,
		SLEEPING_SIDE,
		SLEEPING_BACK

	};
	enum Weapons
	{
		SWORD,
		SPINSWORD
	};
public:
	Link();
	~Link();

	virtual void Update();
	virtual void Render();

	bool IsAttack();


	void SetUnarmed();
	void SpinAttack();
	void AttackEnd(AnimState state);
	
	virtual void GetDamaged(Vector2 vector, int damage);
	void GetFall(Vector2 revivePosition,int damage);
	void EndFall();



	bool& CanControl() { return canControl; }
	bool& IsHide() { return isHide; }

	Direct& LinkDirect() { return direct; }

	Weapon* GetWeapon() { return weapon; }
	Weapon* GetMagic() { return magic; }

	Vector2& OldPosition() { return oldPosition; }

private:


	// Character을(를) 통해 상속됨
	void AddAction() override;
	Direct direct = FORWARD;
	
	float sleepTime = 0.0f;

	bool isAttack = false;

	bool isSleep = false;

	bool canControl = true;

	bool isHide = false;
	
	int HP = 10;
	Vector2 oldPosition = {};
	Vector2 revivePosition = {};
	map<int,Weapon*> weapons;

	Weapon* weapon = nullptr;
	Weapon* magic = nullptr;
};

