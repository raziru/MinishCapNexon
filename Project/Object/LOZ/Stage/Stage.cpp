#include "Framework.h"
#include "Stage.h"

Stage::Stage(Link* link)
	:link(link)
{

}

void Stage::Update()
{
	background->translation = WIN_CENTER;
	background->Update();
	monsters->Update();
	tiles->Update();

	MonsterCollision();
	TileCollision();
	if (!isClear)
	{
		BackgroundCollision();
	}

}

void Stage::Render()
{
	background->Render();
	tiles->Render();
	monsters->Render();
}

void Stage::SetStage(Link* link)
{
	link->SetParent(background);
	isClear = false;
}


bool Stage::CheckClear()
{
	for (Monster* monster : monsters->GetBody())
	{
		if (monster->IsActive())
		{

			return false;
		}
	}
	return true;
}

void Stage::MonsterCollision()
{
	if (link->GetWeapon()->IsActive())
	{
		for (Monster* monster : monsters->GetBody())
		{
			if (!monster->IsActive())
			{
				continue;
			}

			if (link->GetWeapon()->BodyCollider()->Collision(monster->BodyCollider()))
			{
				monster->GetDamaged(monster->GlobalPostion() - link->GlobalPostion(), link->GetWeapon()->Power());
			}
		}

	}

	for (Monster* monster : monsters->GetBody())
	{
		if (!monster->IsActive()|| !link->BodyCollider()->IsActive())
		{
			continue;
		}
		if (link->BodyCollider()->Collision(monster->BodyCollider()))
		{
			link->GetDamaged((link->GlobalPostion() - monster->GlobalPostion()), 0);

		}
		if (link->BodyCollider()->Collision(monster->AggroRadius()))
		{
			monster->MoveToLink(link);
		}
		else
		{
			monster->FindLink() = false;
		}

	}
}

void Stage::TileCollision()
{
	if (!link->BodyCollider()->IsActive())
	{
		return;
	}
	for (Tile* tile : tiles->GetBody())
	{
		if (!tile->IsActive())
		{
			continue;
		}

		if (link->BodyCollider()->Collision(tile->BodyCollider()))// &&link->BodyCollider()->IsActive())
		{
			tile->OnCollision() = true;
		}
		else
		{
			tile->OnCollision() = false;

		}
		for (Monster* monster : monsters->GetBody())
		{
			if (!monster->IsActive())
			{
				continue;
			}
			if (tile->BodyCollider()->Collision(monster->BodyCollider()))
			{
				monster->translation = monster->OldPosition()- (tile->translation - monster->translation)*Time::Delta();

			}
		}
	}
}

void Stage::BackgroundCollision()
{
	if (!background->BodyCollider()->Collision(link->BodyCollider()))
	{
		link->translation = link->OldPosition();
	}
	for (Monster* monster : monsters->GetBody())
	{
		if (!monster->IsActive())
		{
			continue;
		}
		if (!background->BodyCollider()->Collision(monster->BodyCollider()))
		{
			monster->translation = monster->OldPosition();
		}
	}
}

void Stage::PushLink(Link* link, Tile* tile)
{
	Vector2 direct = link->translation - tile->translation;
	link->GetDamaged(direct, 0);
}

void Stage::SpanwMonsterTile(Tile* tile)
{
	tile->IsActive() = false;

	monsterPositions.push_back({ -50,40 });
	monsterPositions.push_back({ 0,40 });
	monsterPositions.push_back({ 50,40 });

	monsters->SetMonsters(monsterPositions, 3);

}

void Stage::ChangeBackgroundTile(Tile* tile)
{

	tile->IsActive() = false;
	background = backgrounds[1];
}

void Stage::FallLinkTile(Link* link, Tile* tile)
{
	tile->BodyCollider()->SetLabel("FallTile");
	Vector2 revivePosition;
	if (link->translation.y - tile->translation.y < 0)
	{
		revivePosition = {
		tile->translation.x,
		tile->translation.y - 60
		};
	}
	else
	{
		revivePosition = {
		tile->translation.x,
		tile->translation.y + 60
		};
	}
	link->CanControl() = false;
	//link->BodyCollider()->IsActive() = false;
	link->GetFall(revivePosition, 0);
	//tile->OnCollision() = false;
}

void Stage::ChangeableFallTileOn(Link* link, Tile* tile)
{
	if (!CheckClear())
	{
		tile->SetAction(0);
		FallLinkTile(link, tile);
	}
	else
	{
		tile->SetAction(1);
	}
}

void Stage::ChangeableFallTileOff(Link* link, Tile* tile)
{
	
	if (!CheckClear())
	{
		tile->SetAction(0);
	}
	else
	{
		tile->SetAction(1);

	}

}

void Stage::WallTile(Link* link, Tile* tile)
{
	link->translation = link->OldPosition()-(tile->translation-link->translation ).GetNormal()*0.01;
}

void Stage::ClearTile(Tile* tile)
{
	isClear = true;
}

void Stage::HideLink(Link* link, Tile* tile)
{
	link->IsHide() = true;
}

void Stage::UnhideLink(Link* link, Tile* tile)
{
	link->IsHide() = false;

}

