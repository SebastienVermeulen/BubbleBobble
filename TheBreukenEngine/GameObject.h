#pragma once
class BaseComponent;

namespace breuk
{
	class GameObject final
	{
	public:
		void Update(const float elapsedSec);
		void Render() const;

		GameObject() = default;
		~GameObject();
		GameObject(const breuk::GameObject& other) = delete;
		GameObject(breuk::GameObject&& other) = delete;
		breuk::GameObject& operator=(const breuk::GameObject& other) = delete;
		breuk::GameObject& operator=(breuk::GameObject&& other) = delete;

		void AddComponent(BaseComponent* pComponent);
		template<class T>
		T* GetComponentOfType();
		template<class T>
		T* GetComponentOfType() const;

	private:
		std::vector<BaseComponent*> m_Components;
	};
}
