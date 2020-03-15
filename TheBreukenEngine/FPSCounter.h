#pragma once
#include "BaseComponent.h"

class FPSCounter final : public BaseComponent
{
public:
	FPSCounter();

	virtual void Initialize() override;
	virtual void Update(const float deltaT) override;

	bool CheckTime(int& count);

private:
	int m_Count;
	float m_ElapsedTime;
};
