#include "Framework.h"
#include "Stage1.h"


Stage1::Stage1(Link* link)
	:Stage(link)
{
	backgrounds.push_back(new Dungeon);
	backgrounds.push_back(new Town);

	background = backgrounds[0];
	SetOnEvents();

	monsters = new OctaManager(3, 3, 3);
	monsters->SetParent(background);
}

Stage1::~Stage1()
{
	for (BackGround* background : backgrounds)
	{
		delete background;
	}
	backgrounds.clear();
	delete tiles;
	delete monsters;
}

void Stage1::SetOnEvents()
{
	tiles = new TileManager(8);

	for (Tile* tile : tiles->GetBody())
	{
		tile->SetParent(background);
	}
	tiles->GetBody()[0]->BodyCollider()->SetLabel("PushLinkTile");
	tiles->GetBody()[1]->BodyCollider()->SetLabel("SpawnTile");
	tiles->GetBody()[2]->BodyCollider()->SetLabel("ClearTile");
	tiles->GetBody()[3]->BodyCollider()->SetLabel("Fall1Tile");
	tiles->GetBody()[4]->BodyCollider()->SetLabel("Fall2Tile");
	tiles->GetBody()[5]->BodyCollider()->SetLabel("HideLinkTile");
	tiles->GetBody()[6]->BodyCollider()->SetLabel("WallTile");
	tiles->GetBody()[7]->BodyCollider()->SetLabel("Wall2Tile");




	Events.push_back(bind(&Stage::PushLink, this, link, tiles->GetBody()[0]));
	Events.push_back(bind(&Stage::SpanwMonsterTile, this, tiles->GetBody()[1]));
	Events.push_back(bind(&Stage::ClearTile, this, tiles->GetBody()[2]));
	Events.push_back(bind(&Stage::FallLinkTile, this, link, tiles->GetBody()[3]));
	Events.push_back(bind(&Stage::ChangeableFallTileOn, this, link, tiles->GetBody()[4]));
	Events.push_back(bind(&Stage::HideLink, this, link, tiles->GetBody()[5]));
	Events.push_back(bind(&Stage::WallTile, this, link, tiles->GetBody()[6]));
	Events.push_back(bind(&Stage::WallTile, this, link, tiles->GetBody()[7]));



	
	tilePositions.push_back(Vector2(100, 100));
	tilePositions.push_back(Vector2(0, 0));
	tilePositions.push_back(Vector2(0, 200));
	tilePositions.push_back(Vector2(32, 92));
	tilePositions.push_back(Vector2(-56, 84));
	tilePositions.push_back(Vector2(0, -82));
	tilePositions.push_back(Vector2(50, -82));
	tilePositions.push_back(Vector2(-50, -82));



	tiles->SetOnEvents(tilePositions, Events, 8);
	tiles->GetBody()[3]->scale = { 17*0.6f,6*0.8f };
	tiles->GetBody()[4]->scale = { 1.7,1.1 };
	tiles->GetBody()[4]->BodyCollider()->scale = { 4,4 };
	tiles->GetBody()[4]->SetOffEvent(bind(&Stage1::ChangeableFallTileOff, this, link, tiles->GetBody()[4]));
	tiles->GetBody()[5]->scale = { 4,5 };
	tiles->GetBody()[5]->SetOffEvent(bind(&Stage1::UnhideLink, this, link, tiles->GetBody()[5]));

	tiles->GetBody()[6]->scale = { 7,5 };
	tiles->GetBody()[7]->scale = { 7,5 };


}

void Stage1::Update()
{	
	Stage::Update();
}

void Stage1::Render()
{
	tiles->GetBody()[0]->BodyCollider()->Debug();
	tiles->GetBody()[1]->BodyCollider()->Debug();
	tiles->GetBody()[2]->BodyCollider()->Debug();
	tiles->GetBody()[3]->BodyCollider()->Debug();
	tiles->GetBody()[4]->BodyCollider()->Debug();
	tiles->GetBody()[7]->BodyCollider()->Debug();


	link->BodyCollider()->Debug();

	Stage::Render();
}

void Stage1::SetStage(Link* link)
{

	Stage::SetStage(link);
	link->OldPosition() = { 0,-220 };
	link->translation = { 0,-220 };

}

