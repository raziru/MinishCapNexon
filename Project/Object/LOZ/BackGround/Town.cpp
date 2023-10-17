#include "Framework.h"
#include "Town.h"

Town::Town()
{
	file = L"BackGround/Hyule_TownSprite.png";
	scale = { 3,3 };
	AddAction();
	curAction = actions[0];
	curAction->Play();

	Vector2 size = { curAction->Size().x * 0.9f , curAction->Size().y * 0.9f };
	bodyCollider = new ColliderRect(size);
	bodyCollider->SetLabel("Town");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;
}

Town::~Town()
{
	delete bodyCollider;

}

void Town::Update()
{
	bodyCollider->Update();
	Actor::Update();
}

void Town::Render()
{
	Actor::Render();
	bodyCollider->Render();
	bodyCollider->Debug();
}

void Town::AddAction()
{
	actions.emplace(0, new Animation(file,1,1));
	actions[0]->SetIndex({ 0 }, false);
}
