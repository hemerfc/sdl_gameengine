#include "Engine.h"

Scene* CreateScene01();

int main(int argc, char* argv[])
{
	Engine engine("Pong");

	engine.SetCurrentScene(CreateScene01());

	engine.GameLoop();
	
	return 0;
}

Scene* CreateScene01()
{
	auto sc = new Scene();

	auto ent1 = sc->CreateEntity();
	new RectComponent(ent1, {20.0f, 105.0f}, {10.0f, 30.0f});
	
	auto ent2 = sc->CreateEntity();
	new RectComponent(ent2, {280.0f, 105.0f}, {10.0f, 30.0f});
	
	auto ent3 = sc->CreateEntity();
	new RectComponent(ent3, {110.0f, 150.0f}, {20.0f, 20.0f});

	return sc;
}


/*

int main(int argc, char* argv[])
{
	SDLManager sdlManager;
	sdlManager.init("Pong", 100, 0, 640, 480);

	auto currentScene = new Scene01(&sdlManager);
	Uint16 frameCounter = 0;
	Sint32 frameTimer = 1000;

	Uint32 newTime = SDL_GetTicks();
	Uint32 oldTime = newTime;
	Uint32 deltaTime = 0;

	while (!sdlManager.Quit)
	{
		sdlManager.FrameControl();

		sdlManager.ProcessEvents();
		currentScene->Update(0.016f);
		
		sdlManager.RenderBegin();
		currentScene->Render();
		sdlManager.RenderEnd();
	}

	sdlManager.Shutdown();
	
	return 0;
}

*/