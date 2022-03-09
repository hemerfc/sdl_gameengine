#include <chrono>
#include <random>
#include "components/BaseComponent.h"
#include "components/PlayerComponent.h"
#include "Entity.h"

PlayerComponent::PlayerComponent(Entity* entity, int playerId)
{
    this->mEntity = entity;
    this->mPlayerId = playerId;
    entity->AddComponent((BaseComponent*)this);
}	

int PlayerComponent::GetComponentType()
{
    return PlayerComponent::TYPE;
}