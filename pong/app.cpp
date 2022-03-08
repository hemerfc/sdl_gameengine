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
	new InputComponent(ent1);
	
	auto ent2 = sc->CreateEntity();
	new RectComponent(ent2, {280.0f, 105.0f}, {10.0f, 30.0f});
	new InputComponent(ent2);
	
	auto ent3 = sc->CreateEntity();
	new RectComponent(ent3, {110.0f, 150.0f}, {20.0f, 20.0f});
	new InputComponent(ent3);

	return sc;
}