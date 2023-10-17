#pragma once
class SpinSword:public Weapon
{
public:
	SpinSword();
	~SpinSword();

	virtual void Update();
	virtual void Render();


private:


	// Character을(를) 통해 상속됨
	void AddAction() override;
	wstring file;
};

