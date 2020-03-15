#pragma once
class BaseComponent
{
public:
	explicit BaseComponent();
	virtual ~BaseComponent();

	BaseComponent(const BaseComponent&) = delete;
	BaseComponent(BaseComponent&&) = delete;
	BaseComponent& operator= (const BaseComponent&) = delete;
	BaseComponent& operator= (const BaseComponent&&) = delete;

	virtual void Initialize() = 0;
	virtual void Update(const float deltaT) = 0;
};
