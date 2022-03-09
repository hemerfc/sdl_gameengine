#include "Engine.h"
#include "components/PlayerComponent.h"
#include "systems/PlayerSystem.h"

Scene* CreateScene01();

int main(int argc, char* argv[])
{
	Engine engine("Pong");

	engine.AddSystem(new PlayerSystem());

	engine.SetCurrentScene(CreateScene01());

	engine.GameLoop();
	
	return 0;
}

Scene* CreateScene01()
{
	auto sc = new Scene();

	auto player1 = sc->CreateEntity();
	new RectComponent(player1, {20.0f, 105.0f}, {10.0f, 30.0f});
	new InputComponent(player1);
	new PlayerComponent(player1, 1);
	
	auto player2 = sc->CreateEntity();
	new RectComponent(player2, {280.0f, 105.0f}, {10.0f, 30.0f});
	new InputComponent(player2);
	new PlayerComponent(player2, 2);
	
	auto ball = sc->CreateEntity();
	new RectComponent(ball, {110.0f, 150.0f}, {20.0f, 20.0f});
	// movementComponent

	return sc;
}