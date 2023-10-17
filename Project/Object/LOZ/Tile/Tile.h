#pragma once
class Tile:public Actor
{
public:
	Tile();
	~Tile();

	virtual void AddAction() override;

	virtual void Update();
	virtual void Render();

	void SetOnEvent(function<void()> Event) { this->OnEvent = Event; }
	void SetOffEvent(function<void()> Event) { this->OffEvent = Event; }

	bool& OnCollision() { return onCollsion; }


	
private:
	function<void()> OnEvent = nullptr;
	function<void()> OffEvent = nullptr;

	bool onCollsion = false;

	// Character을(를) 통해 상속됨

};


