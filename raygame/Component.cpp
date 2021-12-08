#include "Component.h"

Component::Component()
{
}

Component::Component(Actor* owner, const char* name)
{
	m_owner = owner;
	m_name = name;
}

Component::~Component()
{
	delete m_owner;
	delete m_name;
}

void Component::start()
{
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

void Component::onCollision(Actor* collider)
{
}
