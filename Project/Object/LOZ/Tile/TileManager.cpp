#include "Framework.h"
#include "TileManager.h"

TileManager::TileManager(UINT count)
{
	for (UINT i = 0; i < count; i++)
	{
		tiles.push_back(new TransparentTile);
	}

	for (Tile* tile : tiles)
	{
		tile->IsActive() = false;
	}
}

TileManager::~TileManager()
{
	for (Tile* tile : tiles)
	{
		delete tile;
	}
	tiles.clear();
}

void TileManager::Update()
{

	for (Tile* tile : tiles)
	{
		if (!tile->IsActive())
		{
			continue;
		}
		tile->Update();
	}
}

void TileManager::Render()
{
	for (Tile* tile : tiles)
	{
		if (!tile->IsActive())
		{
			continue;
		}
		tile->Render();
	}
}

void TileManager::SetOnEvents(vector<Vector2> positions,vector<function<void()>>Events, UINT count)
{
	for (UINT i = 0; i < count; i++)
	{
		tiles[i]->translation = positions[i];
		tiles[i]->SetOnEvent(Events[i]);
		tiles[i]->IsActive() = true;
	}
	
}
