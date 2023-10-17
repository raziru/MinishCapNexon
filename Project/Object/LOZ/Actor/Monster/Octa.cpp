#include "Framework.h"
#include "Octa.h"


Octa::Octa()
{
	bodyCollider = new ColliderRect({ 14,14 });
	bodyCollider->SetLabel("Octa");
	bodyCollider->SetParent(this);
	bodyCollider->IsActive() = true;

	aggroRadius = new ColliderCircle(40);
	aggroRadius->SetLabel("OctaAggro");
	aggroRadius->SetParent(this);
	aggroRadius->IsActive() = true;

	MaxHP = 3;
	HP = MaxHP;
	power = 2;
	speed = 30;
	clamp = 3;
}

Octa::~Octa()
{
	delete bodyCollider;
	delete aggroRadius;
}

void Octa::Update()
{

	switch (viewDirect)
	{
	case Actor::FORWARD:
		SetAction(IDLE_FORWARD);
		break;
	case Actor::RIGHT:
		SetAction(IDLE_SIDE);
		rotation.y = 0;

		break;
	case Actor::LEFT:
		SetAction(IDLE_SIDE);
		rotation.y = XM_PI;

		break;
	case Actor::BACK:
		SetAction(IDLE_BACK);

		break;
	default:
		break;
	}

	Monster::Update();
	bodyCollider->Update();
	aggroRadius->Update();
}

void Octa::Render()
{
	bodyCollider->Render();
	aggroRadius->Render();
	Monster::Render();
}



