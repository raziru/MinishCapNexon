#pragma once
class Sword:public Weapon
{
public:
	Sword();
	~Sword();


	virtual void Update();
	virtual void Render();
	void AddAction() override;
private:


	// Character을(를) 통해 상속됨

	wstring file;
	
};



