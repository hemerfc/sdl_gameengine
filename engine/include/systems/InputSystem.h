#pragma once

#include <bitset>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <SDL.h>
#include "components/InputComponent.h"
#include "systems/BaseSystem.h"
#include "systems/InputButons.h"
#include "Scene.h"

// Input
class InputSystem : public BaseSystem
{
public: 
	InputSystem();
	void Update(Scene* scene, float dt);
	bool HasQuitEvent();
private:
    void ProcessEvents();
	bool mQuit;
	std::bitset<16> mButtons;
};
