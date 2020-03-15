#pragma once
#include "BaseComponent.h"
#include "Components.h"

struct _TTF_Font;
struct ColorRGB 
{
	int r{}, g{}, b{};
};

	/**
	 * Simple RAII wrapper for an _TTF_Font
	 */
class Font final : public BaseComponent
{
public:
	_TTF_Font* GetFont() const;
	explicit Font(const std::string& fullPath, unsigned int size);
	virtual ~Font();

	Font(const Font&) = delete;
	Font(Font&&) = delete;
	Font& operator= (const Font&) = delete;
	Font& operator= (const Font&&) = delete;

	virtual void Initialize() override;
	virtual void Update(const float deltaT) override;

	inline void SetText(const std::string& text) 
	{
		m_Text = text;
		m_NeedsUpdate = true;
	}
	inline void SetColor(const ColorRGB& color) { m_Color = color; }

	void SetLocalTransform(const glm::vec3& transform);
	Transform* GetLocalTransform() const;

	Texture2D* GetTexture2D() const;

private:
	_TTF_Font* m_pFont;
	Texture2D* m_pTexture;
	Transform* m_pLocalTransform;
	std::string m_Text;
	ColorRGB m_Color;
	unsigned int m_Size;
	bool m_NeedsUpdate;
};
