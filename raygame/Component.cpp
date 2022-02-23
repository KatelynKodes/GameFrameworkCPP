#include "Component.h"

Component::Component()
{
	m_owner = nullptr;
}

Component::~Component()
{
	delete m_owner;
}

void Component::assignOwner(Actor* owner)
{
	if (getOwner())
	{
		return;
	}

	m_owner = owner;
}

void Component::update(float deltaTime)
{
}

void Component::draw()
{
}

void Component::end()
{
}

void Component::onDestroy()
{
}

void Component::onCollision(Actor* collider)
{
}
