#pragma once
class Town: public BackGround
{
public:
	Town();
	~Town();

	virtual void Update() override;
	virtual void Render() override;
private:


	// BackGround��(��) ���� ��ӵ�
	void AddAction() override;

};



