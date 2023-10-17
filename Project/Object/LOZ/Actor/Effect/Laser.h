#pragma once
class Laser:public Effect
{
public:
	Laser();
	~Laser();

	void AddAction() override;
private:
	wstring file2;
	wstring file3;


	// Effect을(를) 통해 상속됨

};

