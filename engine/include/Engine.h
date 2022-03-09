#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "Scene.h"
#include "Entity.h"
#include "systems/BaseSystem.h"
#include "systems/RenderSystem.h"
#include "systems/InputSystem.h"
#include "systems/InputSystem.h"

using namespace std;

class Engine
{
public:	
    Engine(const char* gameTitle);
    void Init();
    void GameLoop();
    void CreateSystems();
    void SetCurrentScene(Scene* scene);
    void AddSystem(BaseSystem* system);

private: 
    Scene* pCurrentScene;
    vector<BaseSystem*> Systems;
    RenderSystem* pRenderSystem;
    InputSystem* pInputSystem;
    string* mGameTitle;
};
