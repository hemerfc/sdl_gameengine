#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "Components/RectComponent.h"
#include "Scene.h"

TEST_CASE( "create scene", "Prove that scene can be created" ){
    auto scene = new Scene();
    
    auto ent1 = scene->CreateEntity();
    new RectComponent(ent1, {20.0f, 105.0f}, {10.0f, 30.0f});
    auto comp = ent1->GetComponent(RectComponent::TYPE);

    REQUIRE( comp->GetComponentType() == RectComponent::TYPE );
}

