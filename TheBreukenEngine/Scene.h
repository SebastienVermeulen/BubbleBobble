#pragma once
#include "SceneManager.h"

namespace breuk
{
	class GameObject;
	class Scene
	{
	public:
		explicit Scene(const std::string& name);
		~Scene();

		void Add(GameObject* object);

		void Update(const float elapsedSec);
		void Render() const;

		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 

		std::string m_Name;
		std::vector<GameObject*> m_Objects{};

		static unsigned int m_IdCounter; 
	};

}
