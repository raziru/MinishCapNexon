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


	// Character��(��) ���� ��ӵ�

	wstring file;
	
};



