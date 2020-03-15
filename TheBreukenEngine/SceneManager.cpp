#include "TheBreukenEnginePCH.h"
#include "SceneManager.h"
#include "Scene.h"

breuk::SceneManager::~SceneManager() 
{
	for (Scene* pScene : m_Scenes) 
	{
		delete pScene;
		pScene = nullptr;
	}
}

void breuk::SceneManager::Update(const float elapsedSec)
{
	for(breuk::Scene* scene : m_Scenes)
	{
		scene->Update(elapsedSec);
	}
}

void breuk::SceneManager::Render()
{
	for (breuk::Scene* scene : m_Scenes)
	{
		scene->Render();
	}
}

breuk::Scene& breuk::SceneManager::CreateScene(const std::string& name)
{
	breuk::Scene* scene = new breuk::Scene(name);
	m_Scenes.push_back(scene);
	return *scene;
}
