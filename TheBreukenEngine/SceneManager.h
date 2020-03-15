#pragma once
#include "Singleton.h"

namespace breuk
{
	class Scene;

	class SceneManager final : public breuk::Singleton<breuk::SceneManager>
	{
	public:
		~SceneManager();

		SceneManager(SceneManager& other) = delete;
		SceneManager(SceneManager&& other) = delete;
		SceneManager operator=(SceneManager& other) = delete;
		SceneManager& operator=(SceneManager&& other) = delete;

		breuk::Scene& CreateScene(const std::string& name);

		void Update(const float elapsedSec);
		void Render();

	private:
		friend class breuk::Singleton<breuk::SceneManager>;
		SceneManager() = default;
		std::vector<breuk::Scene*> m_Scenes;
	};
}
