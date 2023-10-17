#pragma once
class Town: public BackGround
{
public:
	Town();
	~Town();

	virtual void Update() override;
	virtual void Render() override;
private:


	// BackGround을(를) 통해 상속됨
	void AddAction() override;

};



