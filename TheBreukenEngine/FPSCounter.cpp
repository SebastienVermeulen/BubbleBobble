#include "TheBreukenEnginePCH.h"
#include "FPSCounter.h"

FPSCounter::FPSCounter() 
	:m_Count{}
	, m_ElapsedTime{}
{

}

void FPSCounter::Initialize() 
{

}

void FPSCounter::Update(const float deltaT) 
{
	m_Count++;
	m_ElapsedTime += deltaT;
}

bool FPSCounter::CheckTime(int& count) 
{
	if (m_ElapsedTime >= 1.0f) 
	{
		m_ElapsedTime -= 1.0f;
		count = m_Count;
		m_Count = 0;
		return true;
	}
	return false;
}
