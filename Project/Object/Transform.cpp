#include "Framework.h"
#include "Transform.h"

Transform::Transform()
{
	    S = XMMatrixIdentity();
	    R = XMMatrixIdentity();
	    T = XMMatrixIdentity();
	world = XMMatrixIdentity();

}

Transform::~Transform()
{
}

void Transform::Update()
{
	UpdateWorld();
}

void Transform::UpdateWorld()
{
	XMMATRIX P  = XMMatrixTranslation(pivot.x, pivot.y, 0.0f);
	XMMATRIX IP = XMMatrixInverse(nullptr, P);

	S = XMMatrixScaling(scale.x, scale.y, 1.0f);
	R = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
	//roll pitch yaw순으로 곱한다.
	T = XMMatrixTranslation(translation.x, translation.y, 0.0f);

	//translation.x+= 300*Time::Delta();
	world = IP * S * R * T * P;
	if (parent!=nullptr)
	{
		this->world *= parent->world;
	}

	

	XMVECTOR outS, outR, outT;

	XMMatrixDecompose(&outS, &outR, &outT, world);

	XMStoreFloat2(&globalScale,    outS);
	XMStoreFloat2(&globalPosition, outT);


	XMFLOAT4X4 floatworld;

	XMStoreFloat4x4(&floatworld, world);
	//4X4행렬에서 위에서 부터 right, up forward순으로 축분리할 수 있고 맨 아랫줄은 위치(T)를 나타내는 정보이다.
	right = Vector2(floatworld._11, floatworld._12).GetNormal();
	   up = Vector2(floatworld._21, floatworld._22).GetNormal();

}

void Transform::Debug()
{
	assert(label != "");

	if ( ImGui::BeginMenu(label.c_str()))
	{
		ImGui::DragFloat2 ("Scale",       (float*)&scale,        0.1f, 0.1f, 50.0f);

		ImGui::SliderAngle("Rotation",            &rotation.z);

		ImGui::DragFloat2 ("Translation", (float*)&translation, 1.0f, -WIN_WIDTH, WIN_WIDTH);

		ImGui::EndMenu();
	}
}
