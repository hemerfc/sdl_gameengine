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
	this->AddSystem(this->pRenderSystem);

	this->pInputSystem = new InputSystem();
	this->AddSystem(this->pInputSystem);
}

void Engine::AddSystem(BaseSystem* system)
{
	this->Systems.push_back(system);
}

void Engine::GameLoop()
{
	Uint32 lastTime = SDL_GetTicks();
	Uint32 currentTime = SDL_GetTicks();
	float deltaTime = 0;
	float miliseconds = 1000.0;

	while (!this->pInputSystem->HasQuitEvent())
	{	
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime-lastTime)/miliseconds;

		for(auto&& system : this->Systems)
		{
			system->Update(this->pCurrentScene, deltaTime);// 0.016f); // this->mSdlManager.GetRenderer());
		}
		
		lastTime = currentTime;
    }
}

void Engine::SetCurrentScene(Scene* scene)
{
	this->pCurrentScene = scene;
}