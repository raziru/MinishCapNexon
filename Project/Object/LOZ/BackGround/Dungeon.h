#pragma once
class Dungeon:public BackGround
{
public:
	Dungeon();
	~Dungeon();

	virtual void Update() override;
	virtual void Render() override;

private:


	// BackGround��(��) ���� ��ӵ�
	void AddAction() override;

};

