#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec3.hpp>
#pragma warning(pop)

#include "BaseComponent.h"

class Transform final : public BaseComponent
{
public:
	Transform();
	virtual ~Transform();

	Transform(Transform& other) = delete;
	Transform(Transform&& other) = delete;
	Transform operator=(Transform& other) = delete;
	Transform& operator=(Transform&& other) = delete;

	virtual void Initialize() override;
	virtual void Update(const float deltaT) override;

	const glm::vec3& GetPosition() const { return m_Position; }
	void SetPosition(float x, float y, float z);
private:
	glm::vec3 m_Position;
};
