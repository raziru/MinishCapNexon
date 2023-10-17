#pragma once
class Stage2:public Stage
{
public:
	Stage2(Link* link);
	~Stage2();
	void SetOnEvents() override;
	virtual void Update();
	virtual void Render();

	void SetStage(Link* link);

private:

	Vatti* vatti = nullptr;
	// Stage을(를) 통해 상속됨

};



