#include "Framework.h"
#include "Link.h"

Link::Link()
{
	file = L"Character/Link.png";
	weapons.emplace(SWORD,     new Sword);
	weapons.emplace(SPINSWORD, new SpinSword);

	for (pair<int, Weapon*> weapon : weapons)
	{
		weapon.second->SetParent(this);
		weapon.second->translation = { 0,0 };
		weapon.second->IsActive() = false;
	}

	AddAction();

	curAction = actions[IDLE_FORWARD];
	curAction->Play();
	moveSpeed = 100.0f;

	bodyCollider = new ColliderRect({20,20});
	bodyCollider->SetParent(this);
	bodyCollider->SetLabel("Link");
	bodyCollider->IsActive() = true;

	weapon = weapons[SPINSWORD];

}

Link::~Link()
{
	delete bodyCollider;
	for (pair<int, Weapon*> weapon: weapons)
	{
		delete weapon.second;
	}
	weapons.clear();
}

void Link::Update()
{
	oldPosition = translation;


	moveDir = Vector2();


	if(canControl)
	{
		if (KEY_PRESS('A') && KEY_PRESS(VK_LSHIFT))
		{

			moveDir.x -= 1;


			rotation.y = 0;

			//scale.x *= +1;
			direct = RIGHT;
			moveSpeed = 200.0f;
			SetAction(ROLL_SIDE);


		}
		else if (KEY_PRESS('A'))
		{
			moveDir.x -= 1;


			rotation.y = 0;

			//scale.x *= +1;
			direct = RIGHT;

			moveSpeed = 100.0f;


			SetAction(WALK_SIDE);


		}
		else if (KEY_PRESS('D') && KEY_PRESS(VK_LSHIFT))
		{
			moveDir.x += 1;
			rotation.y = XM_PI;

			//scale.x *= -1;

			direct = LEFT;
			moveSpeed = 200.0f;

			SetAction(ROLL_SIDE);

		}
		else if (KEY_PRESS('D'))
		{
			moveDir.x += 1;
			rotation.y = XM_PI;

			//scale.x *= -1;

			direct = LEFT;
			moveSpeed = 100.0f;

			SetAction(WALK_SIDE);


		}
		else if (KEY_PRESS('W') && KEY_PRESS(VK_LSHIFT))
		{

			moveDir.y += 1;

			direct = BACK;
			moveSpeed = 200.0f;

			SetAction(ROLL_BACK);

		}
		else if (KEY_PRESS('W'))
		{

			moveDir.y += 1;

			direct = BACK;
			moveSpeed = 100.0f;

			SetAction(WALK_BACK);

		}
		else if (KEY_PRESS('S') && KEY_PRESS(VK_LSHIFT))
		{
			moveDir.y -= 1;

			direct = FORWARD;
			moveSpeed = 200.0f;
			SetAction(ROLL_FORWARD);



		}

		else if (KEY_PRESS('S'))
		{
			moveDir.y -= 1;

			direct = FORWARD;
			moveSpeed = 100.0f;


			SetAction(WALK_FORWARD);


		}


	}
	translation += moveDir.GetNormal() * moveSpeed * Time::Delta();

	if (moveDir.Length() == 0 && IsAttack() != true)
	{
		switch (direct)
		{
		case Link::FORWARD:
			SetAction(IDLE_FORWARD);
			break;
		case Link::RIGHT:
			SetAction(IDLE_SIDE);
			rotation.y = 0;
			break;
		case Link::LEFT:
			SetAction(IDLE_SIDE);
			rotation.y = XM_PI;
			break;
		case Link::BACK:
			SetAction(IDLE_BACK);
			break;
		default:
			break;
		}
	}


	if (KEY_DOWN(VK_SPACE)&&!weapon->IsActive())
	{
		weapon = weapons[SWORD];
		weapon->IsActive() = true;
		isAttack = true;
		switch (direct)
		{
		case Link::FORWARD:
			rotation.y = 0;

			weapon->rotation.z = XM_PIDIV2;
			weapon->translation = { 13,-13 };
			SetAction(FOLK_FORWARD);

			break;
		case Link::RIGHT:
			weapon->translation = { -13,-13 };
			SetAction(FOLK_SIDE);
			rotation.y = 0;
			break;
		case Link::LEFT:
			weapon->translation = { -13,-13 };

			SetAction(FOLK_SIDE);
			rotation.y = XM_PI;


			break;
		case Link::BACK:
			rotation.y = 0;
			weapon->rotation.z = -XM_PIDIV2;
			weapon->translation = { -13, +13 };

			SetAction(FOLK_BACK);

			break;
		default:
			break;
		}
		
		
		
	}

	if (KEY_DOWN('Z')&&!weapon->IsActive())
	{
		weapon = weapons[SPINSWORD];

		SpinAttack();

	}

	

	if (KEY_DOWN('C'))
	{
		SetAction(DEAD);

	}


	if (sleepTime>1.0f)
	{
		sleepTime = 0;


		switch (direct)
		{
		case Link::FORWARD:
			SetAction(SLEEP_FORWARD);

			break;
		case Link::RIGHT:
			SetAction(SLEEP_SIDE);
			rotation.y = 0;
			break;
		case Link::LEFT:
			SetAction(SLEEP_SIDE);
			rotation.y = XM_PI;
			break;
		case Link::BACK:
			SetAction(SLEEP_BACK);
			break;
		default:
			break;
		}
		
	}

	if (isSleep)
	{
		
		isSleep = false;
	}
	sleepTime += Time::Delta();
	

	Actor::Update();
	bodyCollider->Update();
	weapon->Update();
}

void Link::Render()
{
	if (isHide)
	{
		return;
	}
	Actor::Render();
	bodyCollider->Render();
	weapon->Render();
	//bodyCollider->Debug();
	//weapon->BodyCollider()->Debug();
}

bool Link::IsAttack()
{


	if (state == FOLK_FORWARD)
		return true;
	if (state == FOLK_SIDE)
		return true;
	if (state == FOLK_BACK)
		return true;
	if (state == DRAW_FORWARD)
		return true;
	if (state == DRAW_SIDE)
		return true;
	if (state == DRAW_BACK)
		return true;
	if (state == ITEM_BIG)
		return true;
	if (state == ITEM_SMALL)
		return true;
	if (state == RUSH_FORWARD)
		return true;
	if (state == RUSH_SIDE)
		return true;
	if (state == RUSH_BACK)
		return true;
	if (state == CHARGE_FORWARD)
		return true;
	if (state == CHARGE_SIDE)
		return true;
	if (state == CHARGE_BACK)
		return true;
	if (state == DAMAGED_FORWARD)
		return true;
	if (state == DAMAGED_SIDE)
		return true;
	if (state == DAMAGED_BACK)
		return true;
	if (state == SPIN_FORWARD)
		return true;
	if (state == SPIN_SIDE)
		return true;
	if (state == SPIN_BACK)
		return true;

	if (state == ROLL_FORWARD)
		return true;
	if (state == ROLL_SIDE)
		return true;
	if (state == ROLL_BACK)
		return true;

	if (state == FALL)
		return true;
	if (state == DEAD)
		return true;
	return false;
}


void Link::SetUnarmed()
{
	weapon->IsActive()  = false;
	weapon->rotation    = {};
	weapon->translation = {};
	canControl = true;
}

void Link::SpinAttack()
{
	weapon->SetParent(this);
	weapon->IsActive() = true;
	isAttack = true;
	canControl = false;
	switch (direct)
	{
	case Link::FORWARD:
		SetAction(SPIN_FORWARD);
		break;
	case Link::RIGHT:
		SetAction(SPIN_SIDE);
		break;
	case Link::LEFT:
		SetAction(SPIN_SIDE);
		break;
	case Link::BACK:
		SetAction(SPIN_BACK);

		break;
	default:
		break;
	}
}



void Link::AttackEnd(AnimState state)
{
	
	switch (state)
	{
	case Link::FOLK_FORWARD:
		SetAction(IDLE_FORWARD);
		break;
	case Link::FOLK_SIDE:
		SetAction(IDLE_SIDE);
		break;
	case Link::FOLK_BACK:
		SetAction(IDLE_BACK);
		break;
	default:
		break;
	}
	
}

void Link::GetDamaged(Vector2 vector,int damage)
{
	HP -= damage;

	canControl = false;
	
	switch (direct)
	{
	case Link::FORWARD:
		SetAction(DAMAGED_FORWARD);
		break;
	case Link::RIGHT:
		SetAction(DAMAGED_SIDE);
		rotation.y = 0;
		break;
	case Link::LEFT:
		SetAction(DAMAGED_SIDE);
		rotation.y = XM_PI;
		break;
	case Link::BACK:
		SetAction(DAMAGED_BACK);
		break;
	default:
		break;
	}
	translation += vector.GetNormal() * 30;

}

void Link::GetFall(Vector2 revivePosition, int damage)
{
	HP -= damage;

	canControl = false;

	SetAction(FALL);
	this->revivePosition = revivePosition;
	
}

void Link::EndFall()
{
	SetAction(IDLE_FORWARD);
	translation = revivePosition;
}

void Link::AddAction()
{	

	actions.emplace(IDLE_FORWARD, new Animation(file, 12, 30));
	actions.emplace(IDLE_SIDE,    new Animation(file, 12, 30));
	actions.emplace(IDLE_BACK,    new Animation(file, 12, 30));
	actions[IDLE_FORWARD]->SetIndex({ 0 },false);
	actions[IDLE_SIDE]->SetIndex({ 4 }, false);
	actions[IDLE_BACK]->SetIndex({ 3 }, false);

	actions[IDLE_FORWARD]->SetEndEvent(bind(&Link::SetUnarmed, this));
	actions[IDLE_SIDE]->SetEndEvent(bind(   &Link::SetUnarmed, this));
	actions[IDLE_BACK]->SetEndEvent(bind(   &Link::SetUnarmed, this));
	
	actions.emplace(SLEEP_FORWARD, new Animation(file, 12, 30));
	actions.emplace(SLEEP_SIDE,    new Animation(file, 12, 30));
	actions.emplace(SLEEP_BACK,    new Animation(file, 12, 30));
	actions[SLEEP_FORWARD]->SetIndex({ 0,1,2 },false);
	actions[SLEEP_SIDE]->SetIndex(   { 4,5,6 },false);
	actions[SLEEP_BACK]->SetIndex(   { 3 }, false);

	actions.emplace(SLEEPING_FORWARD, new Animation(file, 12, 30));
	actions.emplace(SLEEPING_SIDE,    new Animation(file, 12, 30));
	actions.emplace(SLEEPING_BACK,    new Animation(file, 12, 30));
	actions[SLEEPING_FORWARD]->SetIndex({ 2 });
	actions[SLEEPING_SIDE]->SetIndex(   { 6 });
	actions[SLEEPING_BACK]->SetIndex(   { 3 });

	actions.emplace(WALK_FORWARD, new Animation(file, 12, 30));
	actions.emplace(WALK_SIDE,    new Animation(file, 12, 30,0));
	actions.emplace(WALK_BACK,    new Animation(file, 12, 30));
	actions[WALK_FORWARD]->SetPart(12,21);
	actions[WALK_SIDE]->SetPart(24, 33);
	actions[WALK_BACK]->SetPart(36, 45);



	actions.emplace(DRAW_FORWARD, new Animation(file, 12, 30));
	actions.emplace(DRAW_SIDE,    new Animation(file, 12, 30));
	actions.emplace(DRAW_BACK,    new Animation(file, 12, 30));
	actions[DRAW_FORWARD]->SetPart(12 * 4 + 4, 12*4,false);
	actions[DRAW_SIDE]->SetIndex({60,61,62,63}, false);
	actions[DRAW_BACK]->SetPart(12 * 4 + 5+4, 12 * 4 + 5, false);

	actions[DRAW_FORWARD]->SetEndEvent(bind(&Link::AttackEnd, this, IDLE_FORWARD));
	actions[DRAW_SIDE]->SetEndEvent(bind(   &Link::AttackEnd, this, IDLE_SIDE));
	actions[DRAW_BACK]->SetEndEvent(bind(   &Link::AttackEnd, this, IDLE_BACK));

	actions.emplace(FOLK_FORWARD, new Animation(file, 12, 30,0,0.05f));
	actions.emplace(FOLK_SIDE, new Animation(file, 12, 30, 0, 0.05f));
	actions.emplace(FOLK_BACK, new Animation(file, 12, 30, 0, 0.05f));
	actions[FOLK_FORWARD]->SetPart(12 * 14 + 5, 12 * 14 + 5 + 2, false);
	actions[FOLK_SIDE]->SetPart(12 * 14 + 5+3+1, 12 * 14 + 5 + 3 + 2, false);
	actions[FOLK_BACK]->SetPart(12 * 15, 12 * 15 + 2, false);

	actions[FOLK_FORWARD]->SetEndEvent(bind(&Link::AttackEnd, this, FOLK_FORWARD));
	actions[FOLK_SIDE]->SetEndEvent(bind(   &Link::AttackEnd, this, FOLK_SIDE));
	actions[FOLK_BACK]->SetEndEvent(bind(   &Link::AttackEnd, this, FOLK_BACK));

	actions.emplace(RUSH_FORWARD, new Animation(file, 12, 30));
	actions.emplace(RUSH_SIDE,    new Animation(file, 12, 30));
	actions.emplace(RUSH_BACK,    new Animation(file, 12, 30));
	actions[RUSH_FORWARD]->SetPart(12 * 6, 12 * 6 + 7, false);
	actions[RUSH_SIDE]->SetPart(12 * 7, 12 * 7 + 7, false);
	actions[RUSH_BACK]->SetPart(12 * 8 , 12 * 8 + 7, false);

	actions[RUSH_FORWARD]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_FORWARD));
	actions[RUSH_SIDE]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_SIDE));
	actions[RUSH_BACK]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_BACK));

	actions.emplace(DAMAGED_FORWARD, new Animation(file, 12, 30));
	actions.emplace(DAMAGED_SIDE,    new Animation(file, 12, 30));
	actions.emplace(DAMAGED_BACK,    new Animation(file, 12, 30));
	actions[DAMAGED_FORWARD]->SetPart(12 * 9, 12 * 9 + 2, false);
	actions[DAMAGED_SIDE]->SetPart(12 * 9+2+1, 12 * 9 + 2+2+1, false);
	actions[DAMAGED_BACK]->SetPart(12 * 9+2+2+2 , 12 * 9 + 2+2+2+2, false);

	actions[DAMAGED_FORWARD]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_FORWARD));
	actions[DAMAGED_SIDE]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_SIDE));
	actions[DAMAGED_BACK]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_BACK));

	actions.emplace(CHARGE_FORWARD, new Animation(file, 12, 30));
	actions.emplace(CHARGE_SIDE,    new Animation(file, 12, 30));
	actions.emplace(CHARGE_BACK,    new Animation(file, 12, 30));
	actions[CHARGE_FORWARD]->SetPart(12 * 13, 12 * 13 + 4, false);
	actions[CHARGE_SIDE]->SetPart(12 * 13+5, 12 * 13 + 5+4, false);
	actions[CHARGE_BACK]->SetPart(12 * 14 , 12 * 14 + 2+2, false);

	actions.emplace(SPIN_FORWARD, new Animation(file, 12, 30,0, 0.05f));
	actions.emplace(SPIN_SIDE,    new Animation(file, 12, 30,0, 0.05f));
	actions.emplace(SPIN_BACK,    new Animation(file, 12, 30,0, 0.05f));
	actions[SPIN_FORWARD]->SetPart(12 * 15 + 3, 12 * 15 + 3 + 8, false);
	actions[SPIN_SIDE]->SetPart(12 * 15 + 3, 12 * 15 + 3 + 8, false);
	actions[SPIN_BACK]->SetPart(12 * 15 + 3, 12 * 15 + 3 + 8, false);

	//actions[SPIN_SIDE]->SetIndex({2,1,0,5,6,7,8,4,3},false);
	//actions[SPIN_SIDE]->SetIndex({ 0,1,2,3,4,5,6,7,6,5,4,3,2,1,0 }, false);
	//actions[SPIN_SIDE]->UpdateTime() = 0.7f;
	//actions[SPIN_BACK]->SetIndex({ 198,197,199,196,187,188,192,193,194,195 }, false);

	actions[SPIN_FORWARD]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_FORWARD));
	actions[SPIN_SIDE]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_SIDE));
	actions[SPIN_BACK]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_BACK));

	actions.emplace(FALL, new Animation(file, 12, 30));
	actions[FALL]->SetPart(12 * 17, 12 * 17 + 6, false);
	actions[FALL]->SetEndEvent(bind(&Link::EndFall, this));



	actions.emplace(DEAD, new Animation(file, 12, 30));
	actions[DEAD]->SetPart(12 * 17 + 6+1, 12 * 17 + 6+1+4, false);
	actions[DEAD]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_BACK));

	actions.emplace(ROLL_FORWARD, new Animation(L"Character/LinkRoll.png", 8, 3));
	actions.emplace(ROLL_SIDE, new Animation(L"Character/LinkRoll.png", 8, 3));
	actions.emplace(ROLL_BACK, new Animation(L"Character/LinkRoll.png", 8, 3));
	actions[ROLL_FORWARD]->SetPart(0, 7,false);
	actions[ROLL_SIDE]->SetPart(8, 14,false);
	actions[ROLL_BACK]->SetPart(16,23,false);

	actions[ROLL_FORWARD]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_FORWARD));
	actions[ROLL_SIDE]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_SIDE));
	actions[ROLL_BACK]->SetEndEvent(bind(&Actor::SetAction, this, IDLE_BACK));
}
