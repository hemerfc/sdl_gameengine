#pragma once

#include <SDL.h>
#include "Entity.h"
#include "components/BaseComponent.h"

// Input
class PlayerComponent : public BaseComponent
{
public: 
	PlayerComponent(Entity* entity, int playerId);
	int GetComponentType();
	static const int TYPE = 999;
	
private: 
	Entity* mEntity;
	int mPlayerId;

};