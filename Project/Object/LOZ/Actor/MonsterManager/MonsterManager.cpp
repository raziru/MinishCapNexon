#include "Framework.h"
#include "MonsterManager.h"

MonsterManager::MonsterManager()
{
	

}

MonsterManager::~MonsterManager()
{
	for (Monster* monster : monsters)
	{
		delete monster;
	}
	monsters.clear();
}

void MonsterManager::Update()
{
	for(Monster* monster: monsters)
	{
		if (!monster->IsActive())
		{
			continue;
		}
		monster->Update();
	}
}

void MonsterManager::Render()
{
	for (Monster* monster : monsters)
	{
		if (!monster->IsActive())
		{
			continue;
		}
		monster->Render();
	}
}

void MonsterManager::SetParent(Transform* parent)
{
	for (Monster* monster : monsters)
	{
		monster->SetParent(parent);
	}
}

void MonsterManager::SetMonsters(vector<Vector2> positions,UINT count)
{
	for (UINT i = 0; i < count; i++)
	{
		monsters[i]->translation = positions[i];
	}
	for (UINT i = 0; i < count; i++)
	{
		if (monsters[i]->IsActive())
		{
			continue;
		}
		monsters[i]->Initialize();
	}
}
