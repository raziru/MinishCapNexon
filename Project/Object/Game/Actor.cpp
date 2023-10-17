#include "Framework.h"
#include "Actor.h"

Actor::Actor()
{
	vertexShader = new VertexShader(L"VertexTexture");
     pixelShader = new  PixelShader(L"PixelTexture");

    worldBuffer = new MatrixBuffer();
	colorBuffer = new ColorBuffer(); 
	//colorBuffer->SetData(Vector4(1, 0, 1, 1));
}

Actor::~Actor()
{
	for (pair<int, Animation*> action : actions)
	{
		delete action.second;
	}
	actions.clear();
    delete vertexShader;
	delete  pixelShader;

	delete worldBuffer;
	delete colorBuffer;
}



void Actor::Update()
{
	
	if (curAction == nullptr)
	{
		return;
	}
	curAction->Update();
	Transform::Update();
}

void Actor::Render()
{
	
	if (curAction==nullptr)
	{
		return;
	}
	
	worldBuffer->SetData(world);
	worldBuffer->VSSetBuffer(0);
	
	
	vertexShader->SetShader();
	 pixelShader->SetShader();
	 if (KEY_DOWN(VK_F1))
	 {
		 colorBuffer->SetData(Vector4(1, 0, 0, 1));

	 }
	 else if(KEY_DOWN(VK_F2))
	 {
		 colorBuffer->SetData(Vector4(1, 1, 1, 1));

	 }
	 colorBuffer->PSSetBuffer(0);
	curAction->Render();
}

void Actor::SetAction(int state)
{
	if (this->state == state)
	{
		return;
	}

	this->state = state;

	curAction = actions[state];
	curAction->Play();
}
