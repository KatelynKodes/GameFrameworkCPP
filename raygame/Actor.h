#pragma once
class Transform2D;
class Collider;
class Component;

class Actor
{
public:
    Actor();
    ~Actor();

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param name="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; }

    /// <summary>
    /// Gets the name of this actor
    /// </summary>
    /// <returns></returns>
    const char* getName() { return m_name; }

    /// <summary>
    /// Sets the name of this actor
    /// </summary>
    /// <returns></returns>
    void SetName(const char* newName) { m_name = newName; }

    /// <summary>
    /// Gets the first component instance attatched to this Actor
    /// That matches the name
    /// </summary>
    /// <param name = "componentName"> The name of the component instance </param>
    template<typename T>
    T* getComponent();

    /// <summary>
    /// Adds a component to the end of the component array
    /// </summary>
    /// <param name = "component"> The new component to attatch to the actor </param>
    /// <returns> A refrence to the component added to the array </returns>
    template<typename T>
    T* addComponent();

    /// <summary>
    /// Adds a component to the end of the component array
    /// </summary>
    /// <param name = "component"> The new component to attatch to the actor </param>
    /// <returns> A refrence to the component added to the array </returns>
    Component* addComponent(Component* component);

    /// <summary>
    /// Removes the first instance found that matches the component name
    /// </summary>
    /// <param name = "component"> The new component to remove from the actor array </param>
    /// <returns> A refrence to the component added to the array </returns>
    bool removeComponent(Component* component);

    /// <summary>
    /// Adds a component to the end of the component array
    /// </summary>
    /// <param name = "componentName"> The new component to attatch to the actor </param>
    /// <returns> A refrence to the component added to the array </returns>
    template<typename T>
    bool removeComponent();

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param name="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);

protected:
    const char* m_name;

private:
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    Component** m_components;
    unsigned int m_componentCount;
};

template<typename T>
inline T* Actor::getComponent()
{
    // Iterate through component array
    for (int i = 0; i < m_componentCount; i++)
    {
        T* temp = dynamic_cast<T*>(m_components[i]);

        //If the name passed through is the same as the component's name...
        if (temp)
            // Return the component
            return (T*)m_components[i];
    }

    return nullptr;
}

template<typename T>
inline T* Actor::addComponent()
{
    T* component = new T();
    Actor* owner = component->getOwner();

    if (owner)
        return nullptr;

    component->assignOwner(this);
    Component** newComponents = new Component * [m_componentCount + 1];

    for (int i = 0; i < m_componentCount; i++)
    {
        newComponents[i] = m_components[i];
    }

    if (m_componentCount > 1)
    {
        delete[] m_components;
    }
    else if (m_componentCount == 1)
    {
        delete m_components;
    }

    newComponents[m_componentCount] = component;
    m_components = newComponents;
    m_componentCount++;

    return (T*)component;
}

template<typename T>
inline bool Actor::removeComponent()
{
    bool componentRemoved = false;

    // Create a new array that's size is one less than the old array
    Component** newArray = new Component * [m_componentCount - 1];

    //Create variable to access tempArray index
    int j = 0;

    //Copy values from old array to new array
    for (int i = 0; i < m_componentCount; i++)
    {
        T* temp = dynamic_cast<T*>(m_components[i]);
        if (!temp)
        {
            newArray[j] = m_components[i];
            j++;
        }
        else
        {
            componentRemoved = true;
        }
    }

    if (componentRemoved)
    {
        delete[] m_components;
        m_components = newArray;
        m_componentCount--;
    }
    else
    {
        delete[] newArray;
    }

    return componentRemoved;
}
