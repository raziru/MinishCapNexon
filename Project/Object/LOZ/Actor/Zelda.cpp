#include "Framework.h"
#include "Zelda.h"


Zelda::Zelda()
{
	translation = WIN_CENTER;
	file = L"Character/Zelda.png";


	AddAction();
	curAction = actions[IDLE_FORWARD];
	curAction->Play();

	bodyCollider = new ColliderRect({ 20,20 });
	bodyCollider->SetParent(this);
	bodyCollider->SetLabel("Zelda");
	bodyCollider->IsActive() = true;
}

Zelda::~Zelda()
{
	delete bodyCollider;
}

void Zelda::Update()
{


	moveDir = Vector2();

	

	Actor::Update();
}

void Zelda::SetDirection(Direct direct)
{

}

void Zelda::Idle()
{
	switch (direct)
	{
	case Zelda::FORWARD:
		SetAction(IDLE_FORWARD);
		break;
	case Zelda::RIGHT:
		SetAction(IDLE_SIDE);
		rotation.y = XM_PI;

		break;
	case Zelda::LEFT:
		SetAction(IDLE_SIDE);
		rotation.y = 0;

		break;
	case Zelda::BACK:
		SetAction(IDLE_BACK);

		break;
	default:
		break;
	}
}

void Zelda::Walk()
{
	switch (direct)
	{
	case Zelda::FORWARD:
		SetAction(WALK_FORWARD);
		break;
	case Zelda::RIGHT:
		SetAction(WALK_SIDE);
		rotation.y = XM_PI;

		break;
	case Zelda::LEFT:
		SetAction(WALK_SIDE);
		rotation.y = 0;

		break;
	case Zelda::BACK:
		SetAction(WALK_BACK);

		break;
	default:
		break;
	}
}

void Zelda::Damaged()
{
	switch (direct)
	{
	case Zelda::FORWARD:
		SetAction(DAMAGED_FORWARD);
		break;
	case Zelda::RIGHT:
		SetAction(DAMAGED_SIDE);
		rotation.y = XM_PI;

		break;
	case Zelda::LEFT:
		SetAction(DAMAGED_SIDE);
		rotation.y = 0;

		break;
	case Zelda::BACK:
		SetAction(DAMAGED_BACK);

		break;
	default:
		break;
	}
}

void Zelda::AddAction()
{
	actions.emplace(IDLE_FORWARD, new Animation(file, 7, 9));
	actions.emplace(IDLE_SIDE,    new Animation(file, 7, 9));
	actions.emplace(IDLE_BACK,    new Animation(file, 7, 9));
	actions[IDLE_FORWARD]->SetIndex({ 0 },true);
	actions[IDLE_SIDE]->SetIndex({ 2 }, true);
	actions[IDLE_BACK]->SetIndex({ 4 }, true);


	actions.emplace(WALK_FORWARD, new Animation(file, 7, 9));
	actions.emplace(WALK_SIDE, new Animation(file, 7, 9));
	actions.emplace(WALK_BACK, new Animation(file, 7, 9));
	actions[WALK_FORWARD]->SetPart(7, 7 + 5, true);
	actions[WALK_SIDE]->SetPart(14, 14 + 5, true);
	actions[WALK_BACK]->SetIndex({ 13, 20, 27}, true);


	actions.emplace(DAMAGED_FORWARD, new Animation(file, 7, 9));
	actions.emplace(DAMAGED_SIDE, new Animation(file, 7, 9));
	actions.emplace(DAMAGED_BACK, new Animation(file, 7, 9));
	actions[DAMAGED_FORWARD]->SetPart(28,28+5, false);
	actions[DAMAGED_SIDE]->SetPart(35,35+5, false);
	actions[DAMAGED_BACK]->SetPart(42,42+5, false);


	actions.emplace(ANIM_DEAD, new Animation(file, 7, 9));
	actions[ANIM_DEAD]->SetPart(56 ,56+4, false);

	actions.emplace(ANIM_PRAY, new Animation(file, 7, 9));
	actions[ANIM_PRAY]->SetIndex({ 34,41,48 }, true);
}
