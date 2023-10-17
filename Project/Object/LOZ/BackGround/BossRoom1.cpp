#include "Framework.h"
#include "BossRoom1.h"

BossRoom1::BossRoom1()
{
	file = L"BackGround/BossRoom1.png";
	scale = { 3,3 };
	AddAction();
	curAction = actions[0];
	curAction->Play();

	Vector2 size = { curAction->Size().x * 0.9f , curAction->Size().y * 0.9f };
	bodyCollider = new ColliderRect(size);
	bodyCollider->SetLabel("BossRoom1");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;
}

BossRoom1::~BossRoom1()
{
	delete bodyCollider;

}

void BossRoom1::Update()
{
	bodyCollider->Update();
	Actor::Update();
}

void BossRoom1::Render()
{
	Actor::Render();
	bodyCollider->Render();
}

void BossRoom1::AddAction()
{
	actions.emplace(0, new Animation(file, 1, 1));
	actions[0]->SetIndex({ 0 }, false);
}
