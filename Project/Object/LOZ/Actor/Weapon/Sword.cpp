#include "Framework.h"
#include "Sword.h"

Sword::Sword()
{
	file = L"Character/Link.png";

	AddAction();

	curAction = actions[0];
	curAction->Play();

	bodyCollider = new ColliderRect({ 20,20 });
	bodyCollider->SetParent(this);
	bodyCollider->SetLabel("Sword");
	bodyCollider->IsActive() = true;
	bodyCollider->translation={ -7, 13 };
	power = 1;
}

Sword::~Sword()
{
	delete bodyCollider;
}

void Sword::Update()
{
	if (!isActive)
	{
		return;
	}
	bodyCollider->Update();
	Actor::Update();
}

void Sword::Render()
{
	if (!isActive)
	{
		return;
	}
	bodyCollider->Render();
	Actor::Render();
}

void Sword::AddAction()
{
	actions.emplace(0, new Animation(file, 12, 30));
	actions[0]->SetIndex({ 7 }, false);
}
