#pragma once
class Effect: public Actor
{
public:
	Effect();
	~Effect();

	virtual void AddAction() = 0;
private:


	// Character��(��) ���� ��ӵ�

};

