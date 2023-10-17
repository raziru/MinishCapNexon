#include "Framework.h"
#include "MainGame.h"


MainGame::MainGame()
{
	srand(time(NULL));
	SetUpImGui();
	FONT->Add("D2Coding", L"D2Coding");

	scene = new ZeldaScene;
}

MainGame::~MainGame()
{
	delete scene;
	Environment::Delete();
	     Device::Delete();
		 Camera::Delete();

	    Time::Delete();
	Keyboard::Delete();
	 Texture::Delete();
	    Font::Delete();
	SoundManager::Delete();
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void MainGame::Update()
{
	SoundManager::GetInstance()->Update();
	    Time::GetInstance()->Update();
	Keyboard::GetInstance()->Update();
	Camera::GetInstance()->Update();
	scene->Update();
	if (KEY_DOWN(VK_TAB))
	{
		HideUI();
	}
}

void MainGame::Render()
{
	ImGuiNewFrame();
	FONT->GetDC()->BeginDraw();

	Environment::GetInstance()->Set();
	Camera::GetInstance()->Set();
	
	scene->Render();
	if(!hiddenInGame)
	{
		Time::GetInstance()->Render();
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData()); 
	}

	
	ImGui::EndFrame();
	FONT->GetDC()->EndDraw();
}

void MainGame::SetUpImGui()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX11_Init(DEVICE, DC);
}

void MainGame::ImGuiNewFrame()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}
