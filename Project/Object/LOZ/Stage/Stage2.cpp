#include "Framework.h"
#include "Stage2.h"

Stage2::Stage2(Link* link)
	:Stage(link)
{
	backgrounds.push_back(new BossRoom1);

	background = backgrounds[0];
	SetOnEvents();

	monsters = new VattiManager();
	monsters->SetParent(background);
	for (Monster* monster: monsters->GetBody())
	{
		monster->IsActive() = false;
	}
	monsters->GetBody()[0]->IsActive() = true;
	monsters->GetBody()[0]->translation = { 0,0 };
}

Stage2::~Stage2()
{
	for (BackGround* background : backgrounds)
	{
		delete background;
	}
	backgrounds.clear();
	delete tiles;
	delete monsters;
	delete vatti;
}

void Stage2::SetOnEvents()
{
	tiles = new TileManager(1);
}

void Stage2::Update()
{
	Stage::Update();

}

void Stage2::Render()
{
	Stage::Render();
}

void Stage2::SetStage(Link* link)
{
	Stage::SetStage(link);
	link->SetParent(background);
	link->OldPosition() = { 0,-50 };
	link->translation = { 0,-50 };
}
