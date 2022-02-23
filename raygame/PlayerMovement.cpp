#include "PlayerMovement.h"


PlayerMovement::PlayerMovement()
{
}

PlayerMovement::PlayerMovement(float speed, MathLibrary::Vector2 velocity) : Component::Component()
{
	m_speed = speed;
	m_velocity = velocity;
}

void PlayerMovement::update(float deltaTime)
{
}
