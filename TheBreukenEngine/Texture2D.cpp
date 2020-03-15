#include "TheBreukenEnginePCH.h"
#include "Texture2D.h"
#include <SDL.h>
#include "Transform.h"

Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_pTexture);
	SAFE_DELETE(m_pTransform);
}

SDL_Texture* Texture2D::GetSDLTexture() const
{
	return m_pTexture;
}

Texture2D::Texture2D(SDL_Texture* texture)
	:BaseComponent{}
	, m_pTransform(new Transform())
{
	m_pTexture = texture;
}

void Texture2D::Initialize()
{

}

void Texture2D::Update(const float)
{

}

void Texture2D::SetLocalTransform(const glm::vec3& transform)
{
	m_pTransform->SetPosition(transform.x, transform.y, transform.z);
}

Transform* Texture2D::GetLocalTransform() const 
{
	return m_pTransform;
}
