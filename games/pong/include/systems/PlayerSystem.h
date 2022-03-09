#pragma once

#include <iostream>
#include <stdexcept>
#include <SDL.h>
#include "systems/BaseSystem.h"
#include "systems/InputButons.h"
#include "components/RectComponent.h"
#include "components/PlayerComponent.h"
#include "components/InputComponent.h"
#include "Scene.h"

// Input
class PlayerSystem : public BaseSystem
{
public: 
	PlayerSystem();
	void Update(Scene* scene, float dt);
private:
    void PlayerLogic(PlayerComponent* player, InputComponent* input, RectComponent* rect, float dt);
};