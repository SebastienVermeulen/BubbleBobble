#include "TheBreukenEnginePCH.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "Font.h"
#include "Renderer.h"

TTF_Font* Font::GetFont() const {
	return m_pFont;
}

Font::Font(const std::string& fullPath, unsigned int size) 
	:BaseComponent{}
	, m_pFont(nullptr)
	, m_Size(size)
	, m_Text()
	, m_pLocalTransform(new Transform())
	, m_Color()
	, m_NeedsUpdate()
	, m_pTexture()
{
	m_pFont = TTF_OpenFont(fullPath.c_str(), size);
	if (m_pFont == nullptr)
	{
		throw std::runtime_error(std::string("Failed to load font: ") + SDL_GetError());
	}
}

Font::~Font()
{
	TTF_CloseFont(m_pFont);
	SAFE_DELETE(m_pTexture);
	SAFE_DELETE(m_pLocalTransform);
}

void Font::Initialize()
{

}

void Font::Update(const float)
{
	if (m_NeedsUpdate) 
	{
		const SDL_Color color = { (Uint8)m_Color.r, (Uint8)m_Color.g, (Uint8)m_Color.b }; // only white text is supported now
		SDL_Surface* surf = TTF_RenderText_Blended(m_pFont, m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		SDL_Texture* texture = SDL_CreateTextureFromSurface(breuk::Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		SAFE_DELETE(m_pTexture);
		m_pTexture = new Texture2D(texture);
		m_NeedsUpdate = false;
	}
}

void Font::SetLocalTransform(const glm::vec3& transform)
{
	m_pLocalTransform->SetPosition(transform.x, transform.y, transform.z);
}

Transform* Font::GetLocalTransform() const
{
	return m_pLocalTransform;
}

Texture2D* Font::GetTexture2D() const 
{
	return m_pTexture;
}
