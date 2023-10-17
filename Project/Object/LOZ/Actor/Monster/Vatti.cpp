#include "Framework.h"
#include "Vatti.h"



Vatti::Vatti()
{
	file = L"Monster/VattiNormal.png";
	file2 = L"Monster/VattiTransform.png";

	AddAction();

	curAction = actions[IDLE_FORWARD];
	curAction->Play();

	bodyCollider = new ColliderRect(curAction->Size());
	bodyCollider->SetLabel("VattiCollider");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;

	aggroRadius = new ColliderCircle(40);
	aggroRadius->SetLabel("Vattiaggro");
	aggroRadius->SetParent(this);
	aggroRadius->IsActive() = true;

	MaxHP = 3;
	HP = MaxHP;
	power = 2;
	speed = 30;
	clamp = 3;
}

Vatti::~Vatti()
{
	delete bodyCollider;
	delete aggroRadius;
}

void Vatti::Update()
{
	switch (viewDirect)
	{
	case Actor::FORWARD:
		SetAction(WALK_FORWARD);
		break;
	case Actor::RIGHT:
		SetAction(WALK_SIDE);
		rotation.y = 0;

		break;
	case Actor::LEFT:
		SetAction(WALK_SIDE);
		rotation.y = XM_PI;

		break;
	case Actor::BACK:
		SetAction(WALK_BACK);

		break;
	default:
		break;
	}
	aggroRadius->Update();
	bodyCollider->Update();
	Monster::Update();
}

void Vatti::Render()
{
	aggroRadius->Render();
	bodyCollider->Render();
	Monster::Render();
}


void Vatti::AddAction()
{
	actions.emplace(IDLE_FORWARD, new Animation(file, 11, 7));
	actions.emplace(IDLE_SIDE,    new Animation(file, 11, 7));
	actions.emplace(IDLE_BACK,    new Animation(file, 11, 7));
	actions[IDLE_FORWARD]->SetIndex({ 0 }, true);
	actions[IDLE_SIDE]->SetIndex({ 2 }, true);
	actions[IDLE_BACK]->SetIndex({ 1 }, true);
	actions.emplace(WALK_FORWARD, new Animation(file, 11, 7));
	actions.emplace(WALK_SIDE, new Animation(file, 11, 7));
	actions.emplace(WALK_BACK, new Animation(file, 11, 7));
	actions[WALK_FORWARD]->SetPart(4, 8, true);
	actions[WALK_SIDE]->SetPart(4, 8, true);
	actions[WALK_BACK]->SetPart(12, 16, true);

	actions.emplace(ATTACK_FORWARD, new Animation(file, 11, 7));
	actions.emplace(ATTACK_SIDE, new Animation(file, 11, 7));
	actions.emplace(ATTACK_BACK, new Animation(file, 11, 7));
	actions[ATTACK_FORWARD]->SetPart(9, 10, true);
	actions[ATTACK_SIDE]->SetPart(9, 10, true);
	actions[ATTACK_BACK]->SetPart(59, 60, true);

	actions.emplace(CHARGE_FORWARD, new Animation(file, 11, 7));
	actions.emplace(CHARGE_SIDE, new Animation(file, 11, 7));
	actions.emplace(CHARGE_BACK, new Animation(file, 11, 7));
	actions[CHARGE_FORWARD]->SetPart(44, 49, true);
	actions[CHARGE_SIDE]->SetPart(44, 49, true);
	actions[CHARGE_BACK]->SetPart(38, 43, true);

	actions.emplace(SPIN_TO_FORWARD, new Animation(file, 11, 7));
	actions.emplace(SPIN_TO_BACK, new Animation(file, 11, 7));
	actions[SPIN_TO_FORWARD]->SetPart(22, 27, true);
	actions[SPIN_TO_BACK]->SetPart(33, 38, true);
	
	actions.emplace(CHANGE_FORM, new Animation(file, 11, 7));
	actions[CHANGE_FORM]->SetPart(71, 66, true);

	actions.emplace(TRANSFORM, new Animation(file2, 5, 2));
	actions[TRANSFORM]->SetAll();


}


