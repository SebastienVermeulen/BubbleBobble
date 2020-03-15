#include "TheBreukenEnginePCH.h"
#include "Scene.h"
#include "GameObject.h"


unsigned int breuk::Scene::m_IdCounter = 0;

breuk::Scene::Scene(const std::string& name) : m_Name(name) {}

breuk::Scene::~Scene() 
{
	for (GameObject* pObject : m_Objects)
	{
		SAFE_DELETE(pObject);
	}
}

void breuk::Scene::Add(GameObject* object)
{
	m_Objects.push_back(object);
}

void breuk::Scene::Update(const float elapsedSec)
{
	for(breuk::GameObject* object : m_Objects)
	{
		object->Update(elapsedSec);
	}
}

void breuk::Scene::Render() const
{
	for (const breuk::GameObject* object : m_Objects)
	{
		object->Render();
	}
}

