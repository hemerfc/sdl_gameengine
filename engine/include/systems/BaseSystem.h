#pragma once

#include <SDL.h>
#include "Scene.h"

// Input
class BaseSystem
{
public: 
	virtual void Update(Scene* scene, float dt);
};