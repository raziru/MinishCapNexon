// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once//헤더파일을 한번만 읽어라

#include "__Others/Targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

#include <time.h>

#include <string>
#include <vector>
#include <map>
#include <functional>

using namespace std;
#include <d3d11.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>

using namespace DirectX;

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#pragma comment(lib, "ImGui.lib")

#include "DirectXTex.h"
#include "DirectXTex.inl"
#pragma comment(lib, "DirectXTex.lib")


#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "dxguid.lib")
#include <shlwapi.h>

#pragma comment(lib, "shlwapi.lib")

#include<d2d1_2.h>
#include<dwrite.h>

#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")

#include <fmod.hpp>

#pragma comment(lib,"fmod_vc.lib")

using namespace FMOD;

#define WIN_WIDTH 1280.0f
#define WIN_HEIGHT 720.0f


#define WIN_CENTER Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.5f

#define DEVICE Device::GetInstance()->GetDevice() //리턴 한 변수를 대체한다.
#define DC     Device::GetInstance()->GetDC()
#define CAMERA Camera::GetInstance()
#define FONT     Font::GetInstance()


#define KEY_UP(p)    Keyboard::GetInstance()->Up(p)    //p:parameter의 약자 긴 함수를 매크로로 사용한다.
#define KEY_DOWN(p)  Keyboard::GetInstance()->Down(p)  //p:parameter의 약자
#define KEY_PRESS(p) Keyboard::GetInstance()->Press(p) //p:parameter의 약자
typedef XMFLOAT3 Vector3;
typedef XMFLOAT4 Vector4;
typedef XMMATRIX Matrix;



#include "Utility/Singleton.h"

#include "Utility/Time.h"
#include "Utility/Keyboard.h"
#include "Utility/Vector2.h"
#include "Object/Transform.h"
#include "Utility/BinaryWriter.h"
#include "Utility/BinaryReader.h"
#include "System/Device.h"
#include "Utility/Font.h"
#include "Utility/SoundManager.h"
#include "Utility/Math.h"

#include "Render/Buffer/VertexLayout.h"
#include "Render/Buffer/VertexBuffer.h"
#include "Render/Buffer/IndexBuffer.h"
#include "Render/Buffer/ConstantBuffer.h"
#include "Render/Buffer/GlobalBuffer.h"
#include "Render/Texture/Texture.h"
#include "Render/Texture/Frame.h"
#include "Render/Texture/Animation.h"

#include "Render/Shader/VertexShader.h"
#include "Render/Shader/PixelShader.h"


#include "System/Environment.h"
#include "System/Camera.h"

#include "Object/Basic/Object.h"
#include "Object/Basic/Polygons.h"

#include "Object/Collision/Collider.h"
#include "Object/Collision/ColliderCircle.h"
#include "Object/Collision/ColliderRect.h"

#include "Object/Game/Actor.h"

#include "Object/LOZ/Actor/Effect.h"
#include "Object/LOZ/Actor/Effect/Fire.h"

#include "Object/LOZ/Tile/Tile.h"
#include "Object/LOZ/Tile/TransparentTile.h"
#include "Object/LOZ/Tile/TileManager.h"

#include "Object/LOZ/Actor/Weapon/Weapon.h"
#include "Object/LOZ/Actor/Weapon/Sword.h"
#include "Object/LOZ/Actor/Weapon/SpinSword.h"

#include "Object/LOZ/Actor/Link.h"
#include "Object/LOZ/Actor/Zelda.h"

#include "Object/LOZ/Actor/Monster/Monster.h"

#include "Object/LOZ/Actor/Monster/Vatti.h"

#include "Object/LOZ/Actor/Monster/Octa.h"
#include "Object/LOZ/Actor/Monster/BlueOcta.h"
#include "Object/LOZ/Actor/Monster/RedOcta.h"
#include "Object/LOZ/Actor/Monster/YellowOcta.h"

#include "Object/LOZ/Actor/MonsterManager/MonsterManager.h"
#include "Object/LOZ/Actor/MonsterManager/OctaManager.h"
#include "Object/LOZ/Actor/MonsterManager/VattiManager.h"

#include "Object/LOZ/BackGround/BackGround.h"
#include "Object/LOZ/BackGround/Town.h"
#include "Object/LOZ/BackGround/Dungeon.h"
#include "Object/LOZ/BackGround/BossRoom.h"
#include "Object/LOZ/BackGround/BossRoom1.h"

#include "Object/LOZ/Stage/Stage.h"
#include "Object/LOZ/Stage/Stage1.h"
#include "Object/LOZ/Stage/Stage2.h"

#include "Scene/Scene.h"
#include "Scene/ZeldaScene.h"


#include "MainGame.h"


extern HWND hWnd;
extern Vector2 mousePos;
extern bool hiddenInGame;
extern void HideUI();
