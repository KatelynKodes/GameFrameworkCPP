#include "PlayerMovement.h"

PlayerMovement::PlayerMovement() : Component()
{
}

PlayerMovement::PlayerMovement(Player* owner, const char* name, float speed, MathLibrary::Vector2 velocity) : Component(owner, name)
{
	m_speed = speed;
	m_velocity = velocity;
}

void PlayerMovement::update(float deltaTime)
{
	int xDirection = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_A) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_D);
	int yDirection = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_S) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_W);

	MathLibrary::Vector2 moveDir = MathLibrary::Vector2((float)xDirection,(float) yDirection);
	
	m_velocity = moveDir.getNormalized() * m_speed * deltaTime;

	getOwner()->getTransform()->getLocalPosition() = m_velocity;
}
