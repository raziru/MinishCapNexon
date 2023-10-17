#pragma once
class ZeldaScene : public Scene
{
public:
	ZeldaScene();
	~ZeldaScene();

	// Scene을(를) 통해 상속됨
	void Update() override;

	void Render() override;

private:
	Link* link = nullptr;

	Stage* stage = nullptr;

	vector<Stage*> stages;

};


