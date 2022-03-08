#include <chrono>
#include <random>
#include "components/BaseComponent.h"
#include "components/RectComponent.h"
#include "Entity.h"

RectComponent::RectComponent(Entity* entity, SDL_FPoint position, SDL_FPoint size)
{
    this->mEntity = entity;
    this->mPosition = position;
    this->mSize = size;
    entity->AddComponent((BaseComponent*)this);
}	

int RectComponent::GetComponentType()
{
    return RectComponent::TYPE;
}