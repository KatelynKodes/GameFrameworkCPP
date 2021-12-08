#pragma once

class Actor;

class Component
{
public:
	// Constructors
	Component();
	Component(Actor* owner, const char* name);
	~Component();

	//Getters
	const char* getName() { return m_name; }
	Actor* getOwner() { return m_owner; }

	//S.U.D.E
	virtual void start();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void end();

	//OnCollision
	virtual void onCollision(Actor* collider);

private:
	Actor* m_owner;
	const char* m_name;
};

