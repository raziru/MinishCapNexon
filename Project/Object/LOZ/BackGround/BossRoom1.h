#pragma once
class BossRoom1:public BossRoom
{
public:
	BossRoom1();
	~BossRoom1();

	virtual void Update();
	virtual void Render();

	void AddAction() override;

private:


	// BossRoom��(��) ���� ��ӵ�

};


