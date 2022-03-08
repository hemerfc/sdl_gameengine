#pragma once

#include <bitset>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include "systems/BaseSystem.h"
#include "systems/Types.h"
#include "Scene.h"

// Input
class EventSystem : public BaseSystem
{
public: 
	EventSystem();
	void Update(Scene* scene, float dt);
	bool HasQuitEvent();
private:
    void ProcessEvents();
	bool mQuit;
	std::bitset<16> mButtons;
};
