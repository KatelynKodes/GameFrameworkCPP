#include "PlayerMovement.h"


PlayerMovement::PlayerMovement()
{
}

PlayerMovement::PlayerMovement(const char* name, float speed, MathLibrary::Vector2 velocity) : Component::Component(name)
{
	m_speed = speed;
	m_velocity = velocity;
}

void PlayerMovement::update(float deltaTime)
{
}
