#pragma once
#include "Actor.h"
#include "Transform2D.h"

class PlayerMovement;

class Player :
	public Actor
{
public:
	//Constructors/deconstructors
	Player() :Actor() {};
	Player(float x, float y, const char* name, float speed, MathLibrary::Vector2 velocity);
	~Player();

	//Gets velocity and speed
	float getSpeed() { return m_speed; }
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	//update method
	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	float m_speed;
};

