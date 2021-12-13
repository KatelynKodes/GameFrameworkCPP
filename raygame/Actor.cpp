#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"
#include "raylib.h"
#include <iostream>


Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

Component* Actor::getComponent(const char* componentName)
{
    // Iterate through component array
    for (int i = 0; i < m_componentCount; i++)
    {
        //If the name passed through is the same as the component's name...
        if (strcmp(m_components[i]->getName(), componentName) == 0)
            // Return the component
            return m_components[i];
    }

    return nullptr;
}

Component* Actor::addComponent(Component* component)
{
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
}

bool Actor::removeComponent(Component* component)
{
    if (!component)
    {
        return false;
    }

    bool componentRemoved = false;

    // Create a new array that's size is one less than the old array
    Component** newArray = new Component * [m_componentCount - 1];

    //Create variable to access tempArray index
    int j = 0;

    //Copy values from old array to new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if(component != m_components[i])
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
        delete component;
    }
    else
    {
        delete[] newArray;
    }

    return componentRemoved;
}

bool Actor::removeComponent(const char* componentName)
{
    if (!componentName)
    {
        return false;
    }

    bool componentRemoved = false;
    Component* componentToDelete = nullptr;

    // Create a new array that's size is one less than the old array
    Component** newArray = new Component * [m_componentCount - 1];

    //Create variable to access tempArray index
    int j = 0;

    //Copy values from old array to new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (strcmp(m_components[i]->getName(), componentName) == 0)
        {
            newArray[j] = m_components[i];
            j++;
        }
        else
        {
            componentRemoved = true;
            componentToDelete = m_components[i];
        }
    }

    if (componentRemoved)
    {
        m_components = newArray;
        m_componentCount--;
        delete componentToDelete;
    }

    return componentRemoved;
}

void Actor::start()
{
    m_started = true;
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        m_components[i]->onCollision(other);
    }
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (m_components[i]->getStarted())
        {
            m_components[i]->start();
        }

        m_components[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
    {
        m_components[i]->draw();
    }
}

void Actor::end()
{
    m_started = false;

    for (int i = 0; i < m_componentCount; i++)
    {
        m_components[i]->end();
    }
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
    {
        m_components[i]->onDestroy();
    }

    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}