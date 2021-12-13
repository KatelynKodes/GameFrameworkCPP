#pragma once

class Actor;

class Component
{
public:
	// Constructors
	Component();
	Component(const char* name);
	virtual ~Component();

	/// <summary>
	/// Gets the name of this component instance
	/// </summary>
	const char* getName() { return m_name; }

	/// <summary>
	/// Gets the owner of this component instance
	/// </summary>
	Actor* getOwner() { return m_owner; }

	bool getStarted() { return m_started; }

	/// <summary>
	/// Assigns an owner to a component if it doesn't already have one
	/// </summary>
	///<param name = "owner"> the new owner being assigned <\param>
	void  assignOwner(Actor* owner);


	virtual void start() { m_started = true; }
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void end();
	virtual void onDestroy();

	/// <summary>
	/// Determines what to do when component collides with an actor
	/// </summary>
	virtual void onCollision(Actor* collider);

private:
	Actor* m_owner;
	const char* m_name;
	bool m_started;
};

