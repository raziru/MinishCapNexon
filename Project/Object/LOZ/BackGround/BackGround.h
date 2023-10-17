#pragma once
class BackGround:public Actor
{
public:
	BackGround();
	~BackGround();

	
	

	virtual void AddAction() = 0 ;
protected:
	wstring file;
	
	
	// Character을(를) 통해 상속됨
};

