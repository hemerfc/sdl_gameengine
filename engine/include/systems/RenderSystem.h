#pragma once

#include <iostream>
#include <stdexcept>
#include <SDL.h>
#include "systems/BaseSystem.h"
#include "components/RectComponent.h"
#include "Scene.h"

// Input
class RenderSystem : public BaseSystem
{
public: 
	RenderSystem(string title, int xpos, int ypos, int width, int height, int logicWidth, int logicHeight);
	~RenderSystem();
	void Update(Scene* scene, float dt);
private:
    void RenderBegin();
    void RenderEnd();   
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
};