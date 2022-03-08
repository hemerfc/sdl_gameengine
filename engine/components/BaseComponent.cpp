#include <chrono>
#include <random>
#include "Components/BaseComponent.h"
#include "Entity.h"

int BaseComponent::GetComponentType()
{
    return -1;
}

Entity* BaseComponent::GetEntity()
{
    return this->mEntity;
}