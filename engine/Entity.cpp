#include <chrono>
#include <random>
#include "Scene.h"
#include "Entity.h"
#include "components/BaseComponent.h"

Entity::Entity(long id) 
{
    this->mId = id;
};

long Entity::GetId()
{
    return mId;
}

void Entity::AddComponent(BaseComponent* component)
{
    long type = component->GetComponentType();
    this->pComponents.emplace(type, component);
}

BaseComponent* Entity::GetComponent(int componentType)
{
    auto component = this->pComponents.find(componentType);

    if(component == this->pComponents.end())
        return nullptr;
    else
        return component->second;
}

map<int, BaseComponent*> Entity::GetComponents()
{
    return this->pComponents;
}
