#pragma once

#include "Components/BaseComponent.h"

// Input
class SpriteComponent : public BaseComponent
{
public: 
	int GetComponentType();
	static const int TYPE = 1;
};