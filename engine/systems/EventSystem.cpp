#include "systems/EventSystem.h"

EventSystem::EventSystem()
{
	this->mQuit = false;
}

void EventSystem::Update(Scene* scene, float dt)
{
    this->ProcessEvents();
}

void EventSystem::ProcessEvents()
{    
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		// check for messages
		switch (event.type) {
			// exit if the window is closed
			case SDL_QUIT:
				this->mQuit = true;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_w:
						mButtons.set(static_cast<std::size_t>(InputButtons::UP));
						break;
					case SDLK_a:
						mButtons.set(static_cast<std::size_t>(InputButtons::LEFT));
						break;
					case SDLK_s:
						mButtons.set(static_cast<std::size_t>(InputButtons::DOWN));
						break;
					case SDLK_d:
						mButtons.set(static_cast<std::size_t>(InputButtons::RIGHT));
						break;	
					case SDLK_ESCAPE:
						this->mQuit = true;
						break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_w:
						mButtons.reset(static_cast<std::size_t>(InputButtons::UP));
					break;
					case SDLK_a:
						mButtons.reset(static_cast<std::size_t>(InputButtons::LEFT));
					break;
					case SDLK_s:
						mButtons.reset(static_cast<std::size_t>(InputButtons::DOWN));
					break;
					case SDLK_d:
						mButtons.reset(static_cast<std::size_t>(InputButtons::RIGHT));
					break;
				}
				break;
		}
	}
}

bool EventSystem::HasQuitEvent()
{    
	return this->mQuit;
}

