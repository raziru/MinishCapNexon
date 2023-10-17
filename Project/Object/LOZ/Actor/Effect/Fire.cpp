#include "Framework.h"
#include "Fire.h"

Fire::Fire()
{

	file = L"Effect/Fire/Fire.png";
	file2 = L"Effect/Fire/Movingfire.png";

	AddAction();
	curAction = actions[1];
	curAction->Play();
}

Fire::~Fire()
{
}

void Fire::AddAction()
{
	actions.emplace(0, new Animation(file, 6, 1));
	actions[0]->SetPart(0, 5, true);

	actions.emplace(1, new Animation(file2, 4, 1));
	actions[1]->SetPart(0,3, true);

	
}
