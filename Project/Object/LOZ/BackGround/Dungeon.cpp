#include "Framework.h"
#include "Dungeon.h"

Dungeon::Dungeon()
{
	file = L"BackGround/Cythal1.png";
	scale = { 3,3 };
	AddAction();
	curAction = actions[0];
	curAction->Play();


	Vector2 size = { curAction->Size().x * 0.6f , curAction->Size().y * 0.85f };
	bodyCollider = new ColliderRect(size);
	bodyCollider->SetLabel("Dungeon");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;
}

Dungeon::~Dungeon()
{
	delete bodyCollider;
}

void Dungeon::Update()
{
	bodyCollider->Update();
	Actor::Update();
}

void Dungeon::Render()
{
	Actor::Render();
	bodyCollider->Render();
	bodyCollider->Debug();
}

void Dungeon::AddAction()
{
	actions.emplace(0, new Animation(file, 1, 1));
	actions[0]->SetIndex({ 0 }, false);
}
