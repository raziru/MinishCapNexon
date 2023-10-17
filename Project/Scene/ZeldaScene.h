#pragma once
class ZeldaScene : public Scene
{
public:
	ZeldaScene();
	~ZeldaScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;

	void Render() override;

private:
	Link* link = nullptr;

	Stage* stage = nullptr;

	vector<Stage*> stages;

};


