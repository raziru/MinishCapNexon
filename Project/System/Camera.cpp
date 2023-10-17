#include "Framework.h"
#include "Camera.h"


Camera::Camera()
{
	viewBuffer = new MatrixBuffer();
	transform = new Transform();
}

Camera::~Camera()
{
	delete viewBuffer;
	delete transform;
}

void Camera::Update()
{
	transform->Update();
	if (target == nullptr)
	{
		FreeMode();
	}
	else
	{
		TargetMode();
	}
	if (KEY_PRESS(VK_SHIFT))
	{
		speed = 300.0f;
	}
	else
	{
		speed = 100.0f;
	}
}

void Camera::Set()
{
	Matrix viewMatrix = XMMatrixInverse(nullptr, transform->GetWorld());

	viewBuffer->SetData(viewMatrix);
	viewBuffer->VSSetBuffer(1);

}

void Camera::FreeMode()
{
	Vector2 moveDir = {};

	if (KEY_PRESS(VK_RBUTTON))
	{
		if (KEY_PRESS('A'))
			moveDir.x += -1;
		if (KEY_PRESS('D'))
			moveDir.x += +1;
		if (KEY_PRESS('S'))
			moveDir.y += -1;
		if (KEY_PRESS('W'))
			moveDir.y += +1;
	}

	transform->translation += moveDir.GetNormal() * speed * Time::Delta();

}

void Camera::TargetMode()
{
	
	Vector2 destination = target->GlobalPostion() - offset;
	
	//선형 보간 - Linear Interpolatin(Lerp)
	transform->translation = Vector2::Lerp(transform->translation,destination,0.5);


}
