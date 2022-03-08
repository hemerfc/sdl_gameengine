#include "systems/RenderSystem.h"

RenderSystem::RenderSystem(string title, int xpos, int ypos, int width, int height, int logicWidth, int logicHeight)
{
	this->pWindow = SDL_CreateWindow(title.c_str(), 0, 0, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

	if (this->pWindow == NULL)
	{        
        string msg("SDL could not create window! SDL Error: ");
        string error(SDL_GetError());

	    std::cout << msg << error << std::endl;
        throw std::runtime_error(msg + error);
	}

	std::cout << "SDL Window creation success" << std::endl;

	this->pRenderer = SDL_CreateRenderer(this->pWindow, -1, 0);

	if (pRenderer < 0) // renderer init error
	{        
        string msg("SDL could not create renderer! SDL Error: ");
        string error(SDL_GetError());

	    std::cout << msg << error << std::endl;
        throw std::runtime_error(msg + error);
	}

	SDL_DisplayMode dm;
	SDL_GetDesktopDisplayMode(0, &dm);
	int w = dm.w;
	int h = dm.h;

	//SDL_SetWindowFullscreen(m_pWindow, SDL_WINDOW_FULLSCREEN);

	SDL_RenderSetLogicalSize(this->pRenderer, 320, 240);

	std::cout << "SDL Renderer creation success" << std::endl;
}

RenderSystem::~RenderSystem()
{
	SDL_DestroyRenderer(this->pRenderer);
	SDL_DestroyWindow(this->pWindow);
}

void RenderSystem::Update(Scene* scene, float dt)
{
	this->RenderBegin();

    auto entities = scene->GetEntities();
    for (auto ent : entities)
    {
        auto comp = ent.second->GetComponent(RectComponent::TYPE);

        if(comp != nullptr)
        {
            auto rectComp = (RectComponent*)comp;

            SDL_Rect rect;
            rect.x = (int)rectComp->mPosition.x;
            rect.y = (int)rectComp->mPosition.y;
            rect.w = (int)rectComp->mSize.x;
            rect.h = (int)rectComp->mSize.y;
            
            SDL_RenderFillRect(this->pRenderer, &rect);
        }
    }

	this->RenderEnd();
}

void RenderSystem::RenderBegin()
{    
	/* Select the color for drawing. It is set to red here. */
	SDL_SetRenderDrawColor(this->pRenderer, 0, 0, 0, 255);
	/* Clear the entire screen to our selected color. */
	SDL_RenderClear(this->pRenderer);

	// draw green quarter
	SDL_SetRenderDrawColor(this->pRenderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_Rect greenBorder = { 0, 0, 320, 240};
	SDL_RenderDrawRect(this->pRenderer, &greenBorder );

	// set red border
	SDL_SetRenderDrawColor(this->pRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
}

void RenderSystem::RenderEnd()
{    
	/* Up until now everything was drawn behind the scenes.
		This will show the new, red contents of the window. */
	SDL_RenderPresent(this->pRenderer);
}

