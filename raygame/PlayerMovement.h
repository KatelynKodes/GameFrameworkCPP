#pragma once
#include "Component.h"
#include "raylib.h"
#include "Transform2D.h"
#include "Player.h";

class PlayerMovement :
	public Component
{
public:
	PlayerMovement() : Component() {};
	PlayerMovement(Player* owner, const char* name, float speed, MathLibrary::Vector2 velocity) : Component(owner, name) {};
	void update(float deltaTime) override;

private:
	float m_speed;
	MathLibrary::Vector2 m_velocity;
};

