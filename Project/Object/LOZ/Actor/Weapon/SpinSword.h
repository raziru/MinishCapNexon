#pragma once
class SpinSword:public Weapon
{
public:
	SpinSword();
	~SpinSword();

	virtual void Update();
	virtual void Render();


private:


	// Character��(��) ���� ��ӵ�
	void AddAction() override;
	wstring file;
};

