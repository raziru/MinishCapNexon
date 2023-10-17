#include "Framework.h"
#include "Tile.h"


Tile::Tile()
{
	
	bodyCollider = new ColliderRect({ 10,10 });
	bodyCollider->SetParent(this);
	bodyCollider->SetLabel("Tile");
	bodyCollider->IsActive() = true;
}

Tile::~Tile()
{
	delete bodyCollider;
}

void Tile::AddAction()
{
}

void Tile::Update()
{
	if (!isActive)
	{
		return;
	}
	Actor::Update();
	bodyCollider->Update();
	if (onCollsion)
	{
		if (OnEvent!=nullptr)
		{
			OnEvent();
		}
	}
	else
	{	
		if (OffEvent != nullptr)
		{
			OffEvent();
		}
	}

}

void Tile::Render()
{
	if (!isActive)
	{
		return;
	}
	Actor::Render();
	bodyCollider->Render();

}
