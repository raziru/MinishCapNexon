#include "Framework.h"
#include "OctaManager.h"

OctaManager::OctaManager(UINT red, UINT blue, UINT yellow)
{
	for (UINT i = 0; i < red; i++)
	{
		monsters.push_back(new RedOcta);
	}
	for (UINT i = 0; i < blue; i++)
	{
		monsters.push_back(new BlueOcta);
	}
	for (UINT i = 0; i < yellow; i++)
	{
		monsters.push_back(new YellowOcta);
	}

	for (Monster* monster : monsters)
	{
		monster->IsActive() = false;
	}
}

OctaManager::~OctaManager()
{
}
