#pragma once
#include "Singleton.h"
#include <SDL.h>

class Font;

namespace breuk
{
	class ResourceManager final : public breuk::Singleton<breuk::ResourceManager>
	{
	public:
		void Init(const std::string& data);
		SDL_Texture* LoadTexture(const std::string& file) const;
		Font* LoadFont(const std::string& file, unsigned int size) const;
	private:
		friend class breuk::Singleton<breuk::ResourceManager>;
		ResourceManager() = default;
		std::string m_DataPath;
	};
}
