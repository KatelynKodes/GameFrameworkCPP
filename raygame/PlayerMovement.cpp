#include "PlayerMovement.h"
#include "raylib.h"

PlayerMovement::PlayerMovement() : Component()
{
}

PlayerMovement::PlayerMovement(Actor* owner, const char* name, float speed) : Component(owner, name)
{
	m_speed = speed;
}

void PlayerMovement::update(float deltaTime)
{
	int xDirection;
	int yDirection;

}

void PlayerMovement::draw()
{
}
