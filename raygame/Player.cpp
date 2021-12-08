#include "Player.h"
#include "PlayerMovement.h"

Player::Player() :Actor()
{

}

Player::Player(float x, float y, const char* name, float speed, MathLibrary::Vector2 velocity) : Actor::Actor(x,y,name)
{
	m_speed = speed;
	m_velocity = velocity;
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{

}
