#pragma once
class Fire: public Effect
{
public:
	Fire();
	~Fire();
	void AddAction() override;


private:
	wstring file2;

	// Effect��(��) ���� ��ӵ�

};


