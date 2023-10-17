#pragma once
class Weapon:public Actor
{
public:
	Weapon();
	~Weapon();

	void AddAction() override;

	int Power() { return power; }
protected:
	int power = 0;

	// Character을(를) 통해 상속됨

};

