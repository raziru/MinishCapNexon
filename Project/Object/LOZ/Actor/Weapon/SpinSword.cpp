#include "Framework.h"
#include "SpinSword.h"



SpinSword::SpinSword()
{

	file = L"Character/Link.png";

	AddAction();

	curAction = actions[0];
	curAction->Play();
	bodyCollider = new ColliderCircle(30);
	bodyCollider->SetParent(this);
	bodyCollider->SetLabel("SpinSword");
	bodyCollider->IsActive() = true;

	power = 1;
}

SpinSword::~SpinSword()
{
	delete bodyCollider;
}

void SpinSword::Update()
{
	if (!isActive)
	{
		return;
	}
	bodyCollider->Update();
	Actor::Update();
}

void SpinSword::Render()
{
	if (!isActive)
	{
		return;
	}
	bodyCollider->Render();
	Actor::Render();
}

void SpinSword::AddAction()
{
	actions.emplace(0, new Animation(file, 12, 30));
	actions[0]->SetIndex({ 7 }, false);
}
