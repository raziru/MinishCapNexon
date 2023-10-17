#include "Framework.h"
#include "Monster.h"


Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Update()
{
	oldPosition = translation;

	if(!findLink)
	{
		ChangeDirect();
		switch (viewDirect)
		{
		case Actor::FORWARD:
			direct = { 0,-1 };
			
			break;
		case Actor::RIGHT:
			direct = { 1,0 };
			rotation.y = XM_PI;

			break;
		case Actor::LEFT:
			direct = { -1,0 };
			rotation.y = 0;

			break;
		case Actor::BACK:

			direct = { 0,1 };

			break;
		default:
			break;
		}
	}
	translation += direct * Time::Delta() * speed;
	Actor::Update();
}


void Monster::GetDamaged(Vector2 vector, int damage)
{
	if (!isActive)
	{
		return;
	}
	HP -= damage;

	if (HP<=0)
	{
		isActive = false;
	}
	translation += vector * Time::Delta() * 150;

}

void Monster::Initialize()
{
	oldPosition = translation;
	isActive = true;
	HP = MaxHP;
	SetAction(IDLE_FORWARD);
}

void Monster::MoveToLink(Link* link)
{
	findLink = true;
	direct = (link->translation - this->translation).GetNormal();
	if (direct.y<0)
	{
		viewDirect = FORWARD;
	}
	else if(direct.y > 0)
	{
		viewDirect = BACK;
	}
	else
	{
		if (direct.x>0)
		{
			viewDirect = RIGHT;
		}
		else
		{
			viewDirect = LEFT;
		}
	}
}


void Monster::ChangeDirect()
{
	cumul += Time::Delta();
	if (cumul>=clamp)
	{
		cumul = 0;
		viewDirect = (Direct)(Math::Random(0,4));
	}
}


