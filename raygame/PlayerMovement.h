#pragma once
#include "Component.h"

class PlayerMovement :
	public Component
{
public:
	PlayerMovement() : Component() {};
	PlayerMovement(Actor* owner, const char* name, float speed) : Component(owner, name) {};
	void update(float deltaTime) override;
	void draw() override;

private:
	float m_speed;

};

