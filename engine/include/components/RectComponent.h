#pragma once

#include <SDL2\SDL.h>
#include "Entity.h"
#include "components/BaseComponent.h"

// Input
class RectComponent : public BaseComponent
{
public: 
	RectComponent(Entity* entity, SDL_FPoint position, SDL_FPoint size);
	int GetComponentType();
	static const int TYPE = 3;
	
	SDL_FPoint mPosition;
	SDL_FPoint mSize;

private: 
	Entity* mEntity;

};