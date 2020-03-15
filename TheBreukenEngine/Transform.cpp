#include "TheBreukenEnginePCH.h"
#include "Transform.h"

Transform::Transform()
	:m_Position{}
{

}
Transform::~Transform()
{

}

void Transform::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void Transform::Initialize()
{
}

void Transform::Update(const float)
{
}
