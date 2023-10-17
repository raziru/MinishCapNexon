#include "Framework.h"
#include "RedOcta.h"


RedOcta::RedOcta()
{
	file = L"Monster/RedOcta.png";

	AddAction();

	curAction = actions[IDLE_FORWARD];
	curAction->Play();
	moveSpeed = 100.0f;
	bodyCollider->translation = { -3,0 };

}

RedOcta::~RedOcta()
{
}

void RedOcta::AddAction()
{
	actions.emplace(IDLE_FORWARD, new Animation(file, 4, 4));
	actions.emplace(IDLE_SIDE, new Animation(file, 4, 4));
	actions.emplace(IDLE_BACK, new Animation(file, 4, 4));
	actions[IDLE_FORWARD]->SetPart(0, 1, true);
	actions[IDLE_SIDE]->SetPart(4, 5, true);
	actions[IDLE_BACK]->SetPart(12, 13, true);

	actions.emplace(ATTACK_FORWARD, new Animation(file, 4, 4));
	actions.emplace(ATTACK_SIDE, new Animation(file, 4, 4));
	actions.emplace(ATTACK_BACK, new Animation(file, 4, 4));
	actions[ATTACK_FORWARD]->SetPart(1, 3, true);
	actions[ATTACK_SIDE]->SetPart(5, 7, true);
	actions[ATTACK_BACK]->SetPart(13, 15, true);
}
