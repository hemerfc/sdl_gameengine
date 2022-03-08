#include <chrono>
#include <random>
#include "components/BaseComponent.h"
#include "components/InputComponent.h"
#include "Entity.h"

InputComponent::InputComponent(Entity* entity)
{
    this->mEntity = entity;
    entity->AddComponent((BaseComponent*)this);
}	

int InputComponent::GetComponentType()
{
    return InputComponent::TYPE;
}

std::bitset<16> InputComponent::GetButtons()
{
    return this->mButtons;
}

void InputComponent::SetButtons(std::bitset<16> buttons)
{
    this->mButtons = buttons;
}