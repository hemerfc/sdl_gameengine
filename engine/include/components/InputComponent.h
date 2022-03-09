#pragma once

#include <bitset>
#include <SDL.h>
#include "Entity.h"
#include "components/BaseComponent.h"

// Input
class InputComponent : public BaseComponent
{
public: 
	InputComponent(Entity* entity);
	int GetComponentType();
	static const int TYPE = 4;

	std::bitset<16> GetButtons();
	void SetButtons(std::bitset<16> buttons);
private: 
	Entity* mEntity;
	std::bitset<16> mButtons;
};