#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec3.hpp>
#pragma warning(pop)

#include "BaseComponent.h"

struct SDL_Texture;
class Transform;

	/**
	 * Simple RAII wrapper for an SDL_Texture
	 */
class Texture2D final : public BaseComponent
{
public:
	SDL_Texture* GetSDLTexture() const;
	explicit Texture2D(SDL_Texture* texture);
	virtual ~Texture2D();

	Texture2D(const Texture2D&) = delete;
	Texture2D(Texture2D&&) = delete;
	Texture2D operator= (const Texture2D&) = delete;
	Texture2D& operator= (const Texture2D&&) = delete;

	virtual void Initialize() override;
	virtual void Update(const float deltaT) override;

	void SetLocalTransform(const glm::vec3& transform);
	Transform* GetLocalTransform() const;

private:
	SDL_Texture* m_pTexture;
	Transform* m_pTransform;
};

