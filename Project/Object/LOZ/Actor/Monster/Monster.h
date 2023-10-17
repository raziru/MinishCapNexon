#pragma once
class Monster: public Actor
{
public:
	Monster();
	~Monster();

	virtual void Update();
	
	virtual void GetDamaged(Vector2 vector,int damage);
	
	void Initialize();


	Weapon* GetWeapon() { return weapon; }
	Weapon* GetMagic() { return magic; }
	
	Vector2 OldPosition() { return oldPosition; }

	Collider* AggroRadius() { return aggroRadius; }
	bool& FindLink() { return findLink; }
	void ChangeDirect();
	void MoveToLink(Link* link);
protected:
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
	};

	Direct viewDirect = FORWARD;
	Vector2 direct = {};
	bool findLink = false;
	int MaxHP = 0;
	int HP = MaxHP;
	int power = 0;
	float speed = 0;
	
	float clamp = 0;
	float cumul = 0;
	Vector2 oldPosition = {};
	Weapon* weapon = nullptr;
	Weapon* magic = nullptr;
	Collider* aggroRadius = nullptr;
	// Character을(를) 통해 상속됨

};


