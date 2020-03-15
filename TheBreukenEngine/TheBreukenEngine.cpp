#include "TheBreukenEnginePCH.h"
#include "TheBreukenEngine.h"
#include <chrono>
#include <thread>
#include <SDL.h>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Components.h"
#include "GameObject.h"
#include "Scene.h"

using namespace std;
using namespace chrono;

void breuk::TheBreukenEngine::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw runtime_error(string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"BreukenEngine - Vermeulen Sebastien",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw runtime_error(string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	breuk::Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void breuk::TheBreukenEngine::LoadGame() const
{
	breuk::Scene& scene = breuk::SceneManager::GetInstance().CreateScene("Demo");
	
	breuk::GameObject* pObject = new breuk::GameObject();
	pObject->AddComponent(new Transform());
	pObject->AddComponent(new Texture2D(breuk::ResourceManager::GetInstance().LoadTexture("background.jpg")));
	scene.Add(pObject);
	
	pObject = new breuk::GameObject();
	Transform* transform = new Transform();
	transform->SetPosition(216, 180, 0);
	pObject->AddComponent(transform);
	pObject->AddComponent(new Texture2D(breuk::ResourceManager::GetInstance().LoadTexture("logo.png")));
	scene.Add(pObject);
	
	pObject = new breuk::GameObject();
	transform = new Transform();
	transform->SetPosition(80, 20, 0);
	pObject->AddComponent(transform);
	Font* pFont = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	pFont->SetText("Programming 4 Assignment");
	pFont->SetColor({255,255,255});
	pObject->AddComponent(pFont);
	scene.Add(pObject);

	pObject = new breuk::GameObject();
	transform = new Transform();
	transform->SetPosition(5, 5, 0);
	pObject->AddComponent(transform);
	pFont = ResourceManager::GetInstance().LoadFont("Lingua.otf", 18);
	pFont->SetText("0 FPS");
	pFont->SetColor({ 255,255,0 });
	pObject->AddComponent(pFont);
	pObject->AddComponent(new FPSCounter());
	scene.Add(pObject);
}

void breuk::TheBreukenEngine::Cleanup()
{
	breuk::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void breuk::TheBreukenEngine::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	breuk::ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		breuk::Renderer& renderer = breuk::Renderer::GetInstance();
		breuk::SceneManager& sceneManager = breuk::SceneManager::GetInstance();
		breuk::InputManager& input = breuk::InputManager::GetInstance();

		float elapsedSec{};
		bool doContinue = true;
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			
			doContinue = input.ProcessInput();
			sceneManager.Update(elapsedSec);
			renderer.Render();
			
			elapsedSec = duration<float>(high_resolution_clock::now() - currentTime).count();
		}
	}

	Cleanup();
}
