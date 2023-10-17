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
	// Stage을(를) 통해 상속됨

};

