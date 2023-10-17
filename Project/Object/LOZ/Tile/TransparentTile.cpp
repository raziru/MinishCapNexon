#include "Framework.h"
#include "TransparentTile.h"

TransparentTile::TransparentTile()
{

	file = L"Transparent.png";
	file2 = L"BackGround/Bridge.png";
	AddAction();

	curAction = actions[0];
	curAction->Play();
}

TransparentTile::~TransparentTile()
{
}

void TransparentTile::AddAction()
{
	actions.emplace(0, new Animation(file, 1, 1));
	actions[0]->SetIndex({ 0 }, false);

	actions.emplace(1, new Animation(file2, 1, 1));
	actions[1]->SetIndex({ 0 }, false);
}

