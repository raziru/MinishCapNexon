#include "Framework.h"
#include "ZeldaScene.h"

ZeldaScene::ZeldaScene()
{
	link = new Link;

	stages.push_back(new Stage1(link));
	stages.push_back(new Stage2(link));


	stage = stages[0];
	stage->SetStage(link);

	CAMERA->SetTarget(link);
	SoundManager::GetInstance()->AddSound("Laser", "_Sound/Laser.wav");
}

ZeldaScene::~ZeldaScene()
{
	delete link;
	for (Stage* stage : stages)
	{
		delete stage;
	}
	stages.clear();
}

void ZeldaScene::Update()
{

	stage->Update();
	link->Update();
	if (stage->IsClear())
	{
		stage = stages[1];
		stage->SetStage(link);
	}
	if (KEY_DOWN(VK_CONTROL))
	{
		SoundManager::GetInstance()->Play("Laser");
	}
		
	
}

void ZeldaScene::Render()
{
	stage->Render();
	link->Render();
}
