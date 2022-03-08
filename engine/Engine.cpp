#include "Engine.h"

Engine::Engine(const char* gameTitle)
{
	this->mGameTitle = new string(gameTitle);
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
        string msg("SDL could not initialize! SDL Error: ");
        string error(SDL_GetError());

	    std::cout << msg << error << std::endl;
        throw std::runtime_error(msg + error);
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) 
    {
        string msg("SDL image could not initialize! SDL Error: ");
        string error(IMG_GetError());

	    std::cout << msg << error << std::endl;
        throw std::runtime_error(msg + error);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
	std::cout << "SDL init success" << std::endl;

	this->CreateSystems();
}

void Engine::CreateSystems()
{
	this->pRenderSystem = new RenderSystem(*this->mGameTitle, 0, 0, 640, 480, 320, 240);
	this->Systems.push_back(this->pRenderSystem);

	this->pInputSystem = new InputSystem();
	this->Systems.push_back(this->pInputSystem);
}

void Engine::GameLoop()
{
	Uint32 newTime = SDL_GetTicks();
	Uint32 oldTime = newTime;
	Uint32 deltaTime = 0;

	while (!this->pInputSystem->HasQuitEvent())
	{
		for(auto&& system : this->Systems)
		{
			system->Update(this->pCurrentScene, 0.016f); // this->mSdlManager.GetRenderer());
		}
    }
}

void Engine::SetCurrentScene(Scene* scene)
{
	this->pCurrentScene = scene;
}