#pragma once
class Stage1:public Stage
{
public:
	Stage1(Link* link);
	~Stage1();

	void SetOnEvents() override;

	virtual void Update();
	virtual void Render();

	void SetStage(Link* link);


private:
	// Stage��(��) ���� ��ӵ�

};

