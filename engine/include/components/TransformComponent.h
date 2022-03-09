#pragma once

#include <SDL.h>
#include "Components/BaseComponent.h"

// Input
class TransformComponent : public BaseComponent
{
public: 
	int GetComponentType();
	static const int TYPE = 2;
	
	SDL_FPoint mPosition;
};