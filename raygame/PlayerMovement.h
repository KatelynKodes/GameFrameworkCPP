#pragma once
#include "Component.h"
#include "raylib.h"
#include "Transform2D.h"
#include "Player.h";

class PlayerMovement :
	public Component
{
public:
	PlayerMovement();
	PlayerMovement(const char* name, float speed, MathLibrary::Vector2 velocity);
	void update(float deltaTime) override;

	MathLibrary::Vector2 getVelocity() { return m_velocity; }
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

	float getSpeed() { return m_speed; }
	float setSpeed(float newSpeed) { m_speed = newSpeed; }

private:
	float m_speed;
	MathLibrary::Vector2 m_velocity;
};

