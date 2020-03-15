#include "TheBreukenEnginePCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Components.h"

breuk::GameObject::~GameObject() 
{
	for (BaseComponent* pComponent : m_Components) 
	{
		SAFE_DELETE(pComponent);
	}
}

void breuk::GameObject::Update(const float elapsedSec)
{
	for (BaseComponent* pComponent : m_Components)
	{
		pComponent->Update(elapsedSec);
	}

	FPSCounter* pCounter = static_cast<FPSCounter*>(GetComponentOfType<FPSCounter>());
	if (pCounter)
	{
		int count{};
		if (pCounter->CheckTime(count))
		{
			std::string fps{ std::to_string(count) + " FPS" };

			Font* pFont = static_cast<Font*>(GetComponentOfType<Font>());
			pFont->SetText(fps);
		}
	}
}

void breuk::GameObject::Render() const
{
	const glm::vec3& pos = static_cast<Transform*>(GetComponentOfType<Transform>())->GetPosition();
	Texture2D* pTexture = static_cast<Texture2D*>(GetComponentOfType<Texture2D>());
	Font* pFont = static_cast<Font*>(GetComponentOfType<Font>());

	if (pTexture)
	{
		glm::vec3 localPos = pTexture->GetLocalTransform()->GetPosition();
		if (pTexture)
			Renderer::GetInstance().RenderTexture(*pTexture, pos.x + localPos.x, pos.y + localPos.y);
	}
	if (pFont)
	{
		glm::vec3 localPos = pFont->GetLocalTransform()->GetPosition();
		if (pFont)
			Renderer::GetInstance().RenderTexture(*pFont->GetTexture2D(), pos.x + localPos.x, pos.y + localPos.y);
	}
}

void breuk::GameObject::AddComponent(BaseComponent* pComponent) 
{
	for (BaseComponent* component : m_Components)
	{
		if (component == pComponent)
		{
			return;
		}
	}

	m_Components.push_back(pComponent);
}

template<class T>
T* breuk::GameObject::GetComponentOfType()
{
	for (BaseComponent* component : m_Components)
	{
		T* cast = dynamic_cast<T*>(component);
		if (cast)
			return cast;
	}
	return nullptr;
}

template<class T>
T* breuk::GameObject::GetComponentOfType() const
{
	for (BaseComponent* component : m_Components)
	{
		T* cast = dynamic_cast<T*>(component);
		if (cast)
			return cast;
	}
	return nullptr;
}
