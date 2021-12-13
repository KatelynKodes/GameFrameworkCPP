#include "Player.h"
#include "PlayerMovement.h"
#include "InputComponent.h"
#include "SpriteComponent.h"



Player::Player()
{
}

Player::Player(float x, float y, const char* name, MathLibrary::Vector2 velocity) : Actor::Actor(x,y,name)
{
	m_velocity = velocity;
}

Player::~Player()
{
}

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	//PUT MOVECOMPONENT HERE
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));

	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	//Run the moveComponent getVelocity method

	Actor::update(deltaTime);
}
